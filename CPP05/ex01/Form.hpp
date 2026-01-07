#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("grade is too high!");
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("grade is too Low.");
		}
	};
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(Form const &src);
	Form const & operator=(Form const & rhs);
	~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat& bureaucrat);
};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif