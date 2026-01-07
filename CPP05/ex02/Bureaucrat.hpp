#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Bureaucrat
{
  private :
	const std::string _name;
	int _grade;
  public:
	class GradeTooLowException : public std::exception
	{
	  public :
		virtual const char* what() const throw()
		{
			return ("Grade is too low! Minimum grade is 150.");
		}
	};
	class GradeTooHighException : public std::exception
	{
	  public :
		virtual const char* what() const throw()
		{
			return ("Grade is too high! Maximum grade is 1.");
		}
	};
	Bureaucrat();
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat const & operator=(Bureaucrat const & rhs);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &);
	void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif