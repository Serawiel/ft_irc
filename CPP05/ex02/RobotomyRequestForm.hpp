#ifndef ROBOTOMYREQUESTSFORM_HPP
#define ROBOTOMYREQUESTSFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>
# include <cstdlib> 

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};

#endif