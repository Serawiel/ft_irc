#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class bigint
{
public :
	bigint();
	bigint(unsigned int a);
	bigint(bigint const & src);
	~bigint();

	std::vector<int> unsignedToVector(unsigned int nb);

	bigint operator+(const bigint& nbr) const;
	bigint& operator+=(const bigint& nbr);
	bigint& operator++();
	bigint operator++(int);

	bigint operator<<(unsigned int digit) const;
	bigint& operator<<=(unsigned int digit);
	bigint operator>>(unsigned int digit) const;
	bigint& operator>>=(bigint nb);

	bool operator>(bigint rhs);
	bool operator<(bigint rhs);
	bool operator>=(bigint rhs);
	bool operator<=(bigint rhs);
	bool operator==(bigint rhs);
	bool operator!=(bigint rhs);

	std::vector<int> value;
};

std::ostream& operator<<(std::ostream& os, const bigint& src);

#endif