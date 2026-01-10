#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <climits>
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();

	static bool isInt(const std::string &s);
	static bool isFloat(const std::string &s);
	static bool isDouble(const std::string &s);

	static void convertFromChar(const char &c);
	static void convertFromInt(const std::string &s);
	static void convertFromFloat(const std::string &s);
	static void convertFromDouble(const std::string &s);

  public:
	static void convert(const std::string &literal);
};

#endif