#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isInt(const std::string &s)
{
	size_t	i;

	if (s.empty())
		return (false);
	if (s.find('.') != std::string::npos)
		return (false);
	if (s.find('f') != std::string::npos)
		return (false);
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i >= s.length())
		return (false);
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string &s)
{
	size_t	i;
	bool	digitBeforePoint;
	bool	digitAfterPoint;

	if (s.empty())
		return (false);
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (true);
	if (s[s.length() - 1] != 'f')
		return (false);
	i = 0;
	digitBeforePoint = false;
	digitAfterPoint = false;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i >= s.length() - 1)
		return (false);
	while (i < s.length() - 1 && s[i] != '.')
	{
		if (!std::isdigit(s[i]))
			return (false);
		digitBeforePoint = true;
		i++;
	}
	if (s[i] != '.')
		return (false);
	i++;
	while (i < s.length() - 1)
	{
		if (!std::isdigit(s[i]))
			return (false);
		digitAfterPoint = true;
		i++;
	}
	if (!digitBeforePoint || !digitAfterPoint)
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &s)
{
	size_t	i;
	bool	digitBeforePoint;
	bool	digitAfterPoint;

	if (s.empty())
		return (false);
	if (s == "nan" || s == "+inf" || s == "-inf")
		return (true);
	i = 0;
	digitBeforePoint = false;
	digitAfterPoint = false;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (i >= s.length())
		return (false);
	while (i < s.length() && s[i] != '.')
	{
		if (!std::isdigit(s[i]))
			return (false);
		digitBeforePoint = true;
		i++;
	}
	if (i >= s.length() || s[i] != '.')
		return (false);
	i++;
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return (false);
		digitAfterPoint = true;
		i++;
	}
	if (!digitBeforePoint || !digitAfterPoint)
		return (false);
	return (true);
}

void ScalarConverter::convertFromChar(const char &c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &literal)
{
	char	*end;
	long	value;
	int		intValue;

	value = std::strtol(literal.c_str(), &end, 10);
	if (value > INT_MAX || value < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
		return ;
	}
	intValue = static_cast<int>(value);
	if (intValue < 0 || intValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(intValue))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &s)
{
	float	value;
	double	d;

	value = std::strtof(s.c_str(), NULL);
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	if (std::isnan(value) || std::isinf(value) || value < -2147483648.0f
		|| value >= 2147483648.0f)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == static_cast<int>(value) && value >= -1000000
		&& value <= 1000000)
		std::cout << "float: " << value << ".0f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
	d = static_cast<double>(value);
	if (d == static_cast<int>(d) && d >= -1000000 && d <= 1000000)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &s)
{
	double	value;
	float	f;

	value = std::strtod(s.c_str(), NULL);
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	if (std::isnan(value) || std::isinf(value) || value < -2147483648.0
		|| value >= 2147483648.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	f = static_cast<float>(value);
	if (f == static_cast<int>(f) && f >= -1000000 && f <= 1000000)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (value == static_cast<int>(value) && value >= -1000000
		&& value <= 1000000)
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		convertFromChar(literal[1]);
		return ;
	}
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		convertFromChar(literal[0]);
		return ;
	}
	if (isInt(literal))
	{
		convertFromInt(literal);
		return ;
	}
	if (isFloat(literal))
	{
		convertFromFloat(literal);
		return ;
	}
	if (isDouble(literal))
	{
		convertFromDouble(literal);
		return ;
	}
	std::cerr << "Error: Invalid literal" << std::endl;
}