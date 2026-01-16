#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_database = rhs._database;
	}
	return (*this);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	double	price;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error : data.csv not found." << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string valueStr;
		std::getline(ss, date, ',');
		std::getline(ss, valueStr);
		price = std::atof(valueStr.c_str());
		_database[date] = price;
	}
}

void BitcoinExchange::printDatabase() const
{
	std::map<std::string, double>::const_iterator it;
	for (it = _database.begin(); it != _database.end(); it++)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

std::string BitcoinExchange::trim(std::string str)
{
	size_t	start;
	size_t	end;

	start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	end = str.find_last_not_of(" \t");
	return (str.substr(start, end - start + 1));
}

bool BitcoinExchange::parseDate(std::string date)
{
	int		year;
	int		month;
	int		day;
	bool	isLeapYear;
	int		maxDay;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2026 || (year == 2026 && month > 2))
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	else if (month == 2)
	{
		isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		maxDay = isLeapYear ? 29 : 28;
		if (day > maxDay)
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::parseNumber(const std::string &str)
{
	if (str.empty())
		return (false);
	size_t i = 0;
	bool hasDigit = false;
	bool hasDot = false;
	while (i < str.length())
	{
		if (std::isdigit(str[i]))
			hasDigit = true;
		else if (str[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isspace(str[i]))
			return (false);
		else
			return (false);
		i++;
	}
	return (hasDigit);
}

void BitcoinExchange::processInput(const std::string &filename)
{
	double	value;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string valueStr;
		std::getline(ss, date, '|');
		std::getline(ss, valueStr);
		if (valueStr.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = trim(date);
		valueStr = trim(valueStr);
		if (!parseDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (!parseNumber(valueStr))
		{
			std::cerr << "Error: bad input => " << date << " : " << valueStr << std::endl;
			continue ;
		}
		value = std::atof(valueStr.c_str());
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		std::map<std::string,
			double>::iterator it = _database.lower_bound(date);
		if (it == _database.end())
		{
			--it;
		}
		else if (it->first != date)
		{
			if (it == _database.begin())
			{
				std::cerr << "Error: date too early." << std::endl;
				continue ;
			}
			--it;
		}
		std::cout << date << " => " << value << " = " << it->second
			* value << std::endl;
	}
}
