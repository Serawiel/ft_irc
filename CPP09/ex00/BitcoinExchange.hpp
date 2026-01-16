#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <string>

class BitcoinExchange
{
  private:
	std::map<std::string, double> _database;

  public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void loadDatabase(const std::string &filename);
	void processInput(const std::string &filename);
	void printDatabase() const;
	std::string trim(std::string str);
	bool parseDate(std::string date);
	bool parseNumber(const std::string &str);
};

#endif