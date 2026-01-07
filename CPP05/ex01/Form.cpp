#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _name("Form1"), _isSigned(false), _gradeToSign(100),
	_gradeToExecute(50)
{
	std::cout << "A form is created." << std::endl;
}

Form::Form(const std::string name, const int gradeToSign,
	const int gradeToExecute) : _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw(GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw(GradeTooLowException());
	std::cout << "A form is created." << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "A form is created by copy." << std::endl;
}

Form const &Form::operator=(Form const &rhs)
{
	this->_isSigned = rhs._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " is destroyed." << std::endl;
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw(GradeTooLowException());
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	std::cout << src.getName() << " form, is signed : " << (src.getIsSigned()? "true" : "false") << ". Grade to sign : " << src.getGradeToSign() << ". Grade to execute : " << src.getGradeToExecute() << "." << std::endl;
	return (o);
}