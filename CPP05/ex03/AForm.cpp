#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("AForm1"), _isSigned(false), _gradeToSign(100),
	_gradeToExecute(50)
{
	std::cout << "AForm is created." << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign,
	const int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw(GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw(GradeTooLowException());
	std::cout << "AForm is created." << std::endl;
}

AForm::AForm(AForm const &src) : _name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "AForm is created by copy." << std::endl;
}

AForm const &AForm::operator=(AForm const &rhs)
{
	this->_isSigned = rhs._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " is destroyed." << std::endl;
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw(GradeTooLowException());
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	std::cout << src.getName() << " AForm, is signed : " << (src.getIsSigned()? "true" : "false") << ". Grade to sign : " << src.getGradeToSign() << ". Grade to execute : " << src.getGradeToExecute() << "." << std::endl;
	return (o);
}