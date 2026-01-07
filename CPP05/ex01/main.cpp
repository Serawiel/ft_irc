#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat nullos("Nullos", 120);
	std::cout <<  nullos;
	Bureaucrat boss("Boss", 1);
	std::cout <<  boss;
	Form CERFA("Cerfa20", 100, 50);
	std::cout << CERFA;
	try
	{
		Form invalidCerfa("InvalidCerfa", 151, 1);
		std::cout << invalidCerfa;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Test grade = 151 -> Trying to create a form but " << e.what() << std::endl;
	}
	try
	{
		Form invalidCerfa("InvalidCerfa", 149, 0);
		std::cout << invalidCerfa;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Test grade = 0 -> Trying to create a form but " << e.what() << std::endl;
	}
	nullos.signForm(CERFA);
	boss.signForm(CERFA);
	std::cout << "After signature: " << CERFA; 
	return (0);
}