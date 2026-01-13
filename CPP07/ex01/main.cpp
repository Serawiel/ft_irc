#include "iter.hpp"

void increment(int &x)
{
	x++;
}

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int tab[] = {1, 2, 3, 4, 5};
	std::string tabstr[] = {"ab", "cd", "de"};

	std::cout << "Initial tab:" << std::endl;
	iter(tab, 5, print);
	
	std::cout << "\nAfter incrementation:" << std::endl;
	iter(tab, 5, increment);
	iter(tab, 5, print);
	
	std::cout << "\nTest with string:" << std::endl;
	iter(tabstr, 3, print);

	return 0;
}

