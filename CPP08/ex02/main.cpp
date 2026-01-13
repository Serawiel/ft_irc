#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "\n--- Test 1: Basic stack operations ---" << std::endl << std::endl;
	MutantStack<int> mstack;
	std::cout << "Test empty : " << (mstack.empty() ? "YES" : "NO") << std::endl;
	mstack.push(-42);
	mstack.push(21);
	mstack.push(64);
	std::cout << "Test push -42, 21, 64." << std::endl;
	std::cout << "Test top : " << mstack.top() << std::endl;
	std::cout << "Test size : " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "After pop, size : " << mstack.size() << std::endl;
	std::cout << "Top after pop : " << mstack.top() << std::endl;
}
