#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

int	main(void)
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

	AForm *form1 = intern.makeForm("shrubbery creation", "garden");
	if (form1)
	{
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}

	AForm *form2 = intern.makeForm("robotomy request", "garden");
	if (form2)
	{
		boss.signForm(*form2);
		boss.executeForm(*form2);
		delete form2;
	}

	AForm *form3 = intern.makeForm("presidential pardon", "Arthur");
	if (form3)
	{
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}

	AForm *form4 = intern.makeForm("unknown", "target");
	if (form4)
	{
		delete form4;
	}

	return (0);
}