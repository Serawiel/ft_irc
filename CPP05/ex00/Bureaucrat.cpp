#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Jean-Claude Procédure"), _grade(150)
{
	std::cout << "A bureaucrat called " << this->_name << " is created with the lowest possible grade." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
	std::cout << "A bureaucrat called " << this->_name << " is created with the " << this->_grade << " grade." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "A copy bureaucrat called " << this->_name << " is created." << std::endl;
	*this = src;
}
Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << " is dead of boredom." << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw(GradeTooHighException());
	if (_grade - 1 > 150)
		throw(GradeTooLowException());
	this->_grade--;
	std::cout << _name << " is taking grade !" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 < 1)
		throw(GradeTooHighException());
	if (_grade + 1 > 150)
		throw(GradeTooLowException());
	this->_grade++;
	std::cout << _name << " is loosing grade !" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	std::cout << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (o);
}