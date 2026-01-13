#include "MutantStack.hpp"
#include <list>

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

	std::cout << "\n--- Test 2: Iterators ---" << std::endl << std::endl;
	mstack.push(65);
	mstack.push(56);
	mstack.push(31);
	mstack.push(41);
	std::cout << "Stack content (via iterators) : " << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Stack content (via const iterators) : " << std::endl;
	const MutantStack<int> const_stack(mstack);
	for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "\n--- Test WITH STD::LIST : Basic stack operations ---" << std::endl << std::endl;
	std::list<int> mlist;
	std::cout << "Test empty : " << (mlist.empty() ? "YES" : "NO") << std::endl;
	mlist.push_back(-42);
	mlist.push_back(21);
	mlist.push_back(64);
	std::cout << "Test push -42, 21, 64." << std::endl;
	std::cout << "Test top : " << mlist.back() << std::endl;
	std::cout << "Test size : " << mlist.size() << std::endl;
	mlist.pop_back();
	std::cout << "After pop, size : " << mlist.size() << std::endl;
	std::cout << "Top after pop : " << mlist.back() << std::endl;

	std::cout << "\n--- Test WITH STD::LIST :: Iterators ---" << std::endl << std::endl;
	mlist.push_back(65);
	mlist.push_back(56);
	mlist.push_back(31);
	mlist.push_back(41);
	std::cout << "Stack content (via iterators) : " << std::endl;
	for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Stack content (via const iterators) : " << std::endl;
	const std::list<int> const_list(mlist);
	for (std::list<int>::const_iterator it = const_list.begin(); it != const_list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;


	std::cout << "\n--- Test 3: Iterator operations ---" << std::endl << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "First element: " << *it << std::endl;
	++it;
	std::cout << "After ++it : " << *it << std::endl;
	--it;
	std::cout << "After --it: " << *it << std::endl;
	--ite;
	std::cout << "Last element :" << *ite << std::endl;

	std::cout << "\n--- Test 4: Copy constructor ---" << std::endl;
	MutantStack<int> copy(mstack);
	std::cout << "Original size: " << mstack.size() << std::endl;
	std::cout << "Copy size: " << copy.size() << std::endl;
	copy.push(999);
	std::cout << "After push on copy:" << std::endl;
	std::cout << "Original size: " << mstack.size() << std::endl;
	std::cout << "Copy size: " << copy.size() << std::endl;

	std::cout << "\n--- Test 5: Assignment operator ---" << std::endl;
	MutantStack<int> assigned;
	assigned = mstack;
	std::cout << "Assigned size: " << assigned.size() << std::endl;
	std::cout << "Assigned top: " << assigned.top() << std::endl;

	std::cout << "\n--- Test 6: MutantStack<std::string> ---" << std::endl;
	MutantStack<std::string> str_stack;
	str_stack.push("Hello");
	str_stack.push("World");
	str_stack.push("!");
	std::cout << "String stack: ";
	for (MutantStack<std::string>::iterator it = str_stack.begin(); 
			it != str_stack.end(); 
			++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return 0;
}
