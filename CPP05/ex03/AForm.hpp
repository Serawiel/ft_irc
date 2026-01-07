#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
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
	class FormNotSignedException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("form is not signed.");
		}
	};
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(AForm const &src);
	AForm const & operator=(AForm const & rhs);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const &src);

#endif