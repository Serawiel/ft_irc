#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat tooHigh("tooHigh", 0);
		std::cout << tooHigh;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 'Create a too High Bureaucrat' output : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("tooLow", 151);
		std::cout << tooLow;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 'Create a too Low Bureaucrat' output : " << e.what() << std::endl;
	}
	Bureaucrat BestGrade("BestGrade", 1);
	std::cout << BestGrade;
	try
	{
		BestGrade.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 'Increment too high a Bureaucrat' output : " << e.what() << std::endl;
	}
	Bureaucrat LowestGrade("LowestGrade", 150);
	std::cout << LowestGrade;
	try
	{
		LowestGrade.decrementGrade();
		
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 'Decrement too low a Bureaucrat' output : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bob;
		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;
		bob.decrementGrade();
		std::cout << bob;
	}
	catch (std::exception &e)
	{
		std::cerr << "Normal test : " << e.what() << std::endl;
	}
	return (0);
}