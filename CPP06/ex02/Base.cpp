#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	int	random;

	random = rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	A	*testA;
	B	*testB;
	C	*testC;

	testA = dynamic_cast<A *>(p);
	if (testA != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	testB = dynamic_cast<B *>(p);
	if (testB != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	testC = dynamic_cast<C *>(p);
	if (testC != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...)
	{
	}
}