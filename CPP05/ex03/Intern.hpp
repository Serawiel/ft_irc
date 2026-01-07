#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>
# include <stdexcept>

class Intern
{
  public:
	Intern();
	Intern(Intern const &src);
	Intern const &operator=(Intern const &rhs);
	~Intern();

	AForm *makeForm(std::string formName, std::string target);
};

#endif