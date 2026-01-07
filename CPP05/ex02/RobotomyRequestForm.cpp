#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "Robotomy Request Form is created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form is created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target)
{
	std::cout << "Robotomy Request Form is created by copy." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form is destroyed." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "* BZZZZZZZZ * DRRRRRRR * BZZZZZZ *" << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
	}
}