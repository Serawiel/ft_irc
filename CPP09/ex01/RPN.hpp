#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <cstdlib>

class RPN
{
private:
	std::list<int> _list;
public:
	RPN();
	RPN(const RPN & src);
	RPN & operator=(const RPN & rhs);
	~RPN();

	void calculate(std::string const & str);
};

#endif