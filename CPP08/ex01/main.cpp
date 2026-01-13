#include "Span.hpp"
#include <list>

int	main(void)
{
	std::cout << "=== TEST BASIC ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(-3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.display();
	std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;

	std::cout << "\n=== TEST ADD RANGE WITH LIST ===" << std::endl;
	Span sp2(10);
	std::list<int> list;
	list.push_back(2);
	list.push_back(4);
	list.push_back(20);
	list.push_back(15);
	list.push_back(17);

	sp2.addRange(list.begin(), list.end());
	sp2.display();
	std::cout << "Shortest : " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp2.longestSpan() << std::endl;

	std::cout << "\n=== TEST EXCEPTION ===" << std::endl;
	try
	{
		Span sp3(3);
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(3);
		sp3.addNumber(4);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 10000 NUMBERS ===" << std::endl;
	Span sp4(10000);
	std::vector<int> huge;
	for (int i = 0; i < 10000; i++)
		huge.push_back(i);
	sp4.addRange(huge.begin(), huge.end());
	std::cout << "Added 10000 numbers successfully --> huge size " << huge.size() << std::endl;
	std::cout << "Shortest : " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp4.longestSpan() << std::endl;

	return (0);
}