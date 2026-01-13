#include "easyfind.hpp"
#include <algorithm>
#include <deque>
#include <list>
#include <vector>

void	displayInt(int const &i)
{
	std::cout << i << std::endl;
}

int	main(void)
{
	std::cout << "== TEST 1 : LIST ==" << std::endl;
	std::list<int> lst1;

	lst1.push_back(1);
	lst1.push_back(6);
	lst1.push_back(9);
	lst1.push_back(12);
	lst1.push_back(17);
	std::for_each(lst1.begin(), lst1.end(), displayInt);
	try
	{
		std::list<int>::iterator r = easyfind(lst1, 17);
		std::cout << *r << " found in list !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "== TEST 2 : VECTOR ==" << std::endl;
	std::vector<int> v1;
	for (int i = 1; i <= 5; i++)
	{
		v1.push_back(i * 5);
	}
	std::for_each(v1.begin(), v1.end(), displayInt);
	try
	{
		std::vector<int>::iterator r = easyfind(v1, 10);
		std::cout << *r << " found in vector !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "== TEST 3 : DEQUE ==" << std::endl;
	std::deque<int> d1(5, 10);
	std::for_each(d1.begin(), d1.end(), displayInt);
	try
	{
		std::deque<int>::iterator r = easyfind(d1, 5);
		std::cout << *r << " found in deque !" << std::endl;
	}
		catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}