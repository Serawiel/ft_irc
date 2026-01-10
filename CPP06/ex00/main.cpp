#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		std::cerr << "Examples: ./convert 42, ./convert 'a', ./convert 3.14f" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}