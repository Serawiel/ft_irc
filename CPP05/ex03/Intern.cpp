#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "A random intern is created." << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "A random intern is created by copy." << std::endl;
	*this = src;
}

Intern const &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "A random intern is destroyed." << std::endl;
}

static AForm	*createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};
	AForm *(*creators[3])(std::string) = {createShrubbery, createRobotomy,
		createPresidential};
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			std::cout << "Intern creates " << formName << "." << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Error: form '" << formName << "' does not exist.";
	std::cout << " Available forms:" << std::endl;
	std::cout << "  - shrubbery creation" << std::endl;
	std::cout << "  - robotomy request" << std::endl;
	std::cout << "  - presidential pardon" << std::endl;
	return (NULL);
}