#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int	main(void)
{
	Bureaucrat bigboss("Big boss", 1);
	std::cout << bigboss;
	Bureaucrat boss("Boss", 25);
	std::cout << boss;
	Bureaucrat nullos("Nullos", 150);
	std::cout << nullos;
	ShrubberyCreationForm formhome("home");
	std::cout << formhome;
	RobotomyRequestForm robot("Bender");
	std::cout << robot;
	PresidentialPardonForm grace("Grace");
	std::cout << grace;

	boss.signForm(formhome);
	boss.executeForm(formhome);
	nullos.executeForm(formhome);

	srand(time(NULL));
	nullos.executeForm(robot);
	boss.signForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	nullos.executeForm(robot);

	bigboss.executeForm(grace);
	boss.signForm(grace);
	boss.executeForm(grace);
	bigboss.executeForm(grace);

	return (0);
}