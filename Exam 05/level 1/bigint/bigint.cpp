#include "bigint.hpp"

bigint::bigint() : value(unsignedToVector(0))
{
}

bigint::bigint(unsigned int a) : value(unsignedToVector(a))
{
}

bigint::bigint(bigint const &src) : value(src.value)
{
}

bigint::~bigint()
{
}

std::vector<int> bigint::unsignedToVector(unsigned int nb)
{
	std::vector<int> vec;
	if (nb == 0)
	{
		vec.push_back(0);
		return (vec);
	}
	while (nb > 0)
	{
		vec.push_back(nb % 10);
		nb = nb / 10;
	}
	return (vec);
}

bigint bigint::operator+(const bigint &nbr) const
{
	std::vector<int> vec;
	int rest = 0;
	size_t maxSize = std::max(value.size(), nbr.value.size());
	for (size_t i = 0; i < maxSize; i++)
	{
		int a = (i < value.size()) ? value[i] : 0;
		int b = (i < nbr.value.size()) ? nbr.value[i] : 0;
		if (a + b + rest >= 10)
		{
			vec.push_back((a + b + rest) % 10);
			rest = (a + b + rest) / 10;
		}
		else
			vec.push_back(a + b + rest);
	}
	if (rest > 0)
		vec.push_back(rest);
	bigint result;
	result.value = vec;
	return (result);
}

bigint& bigint::operator+=(const bigint& nbr)
{
	*this = *this + nbr;
	return (*this);
}

bigint& bigint::operator++()
{
	bigint one(1);
	(*this) = (*this) + one;
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint one(1);
	bigint old(*this);
	(*this) = (*this) + one;
	return (old);
}

bigint bigint::operator<<(unsigned int digit) const
{
	bigint result(*this);
	for (unsigned int i = 0; i < digit; i++)
		result.value.insert(result.value.begin(), 0); 
	return (result);
}

bigint& bigint::operator<<=(unsigned int digit)
{
	for (unsigned int i = 0; i < digit; i++)
		this->value.insert(this->value.begin(), 0); 
	return (*this);
}

bigint bigint::operator>>(unsigned int digit) const
{
	bigint result(*this);
	for(unsigned int i = 0; i < digit; i++)
		result.value.erase(result.value.begin());
	return (result);
}

unsigned int vectorToUnsigned(bigint nb)
{
	unsigned int result = 0;
	for (int i = nb.value.size()-1; i >= 0; i--)
	{
		result = result * 10 + nb.value[i];
	}
	return (result);
}

bigint& bigint::operator>>=(bigint nb)
{
	unsigned int digit = vectorToUnsigned(nb);
	for(unsigned int i = 0; i < digit; i++)
		this->value.erase(this->value.begin());
	return (*this);
}

bool bigint::operator>(bigint rhs)
{
	if (this->value.size() > rhs.value.size())
		return (true);
	else if (this->value.size() == rhs.value.size())
	{
		for (int i = this->value.size() - 1; i >= 0; i--)
		{
			if (this->value[i] > rhs.value[i])
				return (true);
			else if (this->value[i] < rhs.value[i])
				return (false);
		}
		return (false);
	}
	else
		return (false);
}

bool bigint::operator<(bigint rhs)
{
	if (this->value.size() < rhs.value.size())
		return (true);
	else if (this->value.size() == rhs.value.size())
	{
		for (int i = this->value.size() - 1; i >= 0; i--)
		{
			if (this->value[i] < rhs.value[i])
				return (true);
			else if (this->value[i] > rhs.value[i])
				return (false);
		}
		return (false);
	}
	else
		return (false);
}

bool bigint::operator>=(bigint rhs)
{
	return (*this > rhs || *this == rhs);
}

bool bigint::operator<=(bigint rhs)
{
	return (*this < rhs || *this == rhs);
}

bool bigint::operator==(bigint rhs)
{
	if (this->value.size() != rhs.value.size())
		return (false);
	for (int i = this->value.size() - 1; i >= 0; i--)
	{
		if (this->value[i] != rhs.value[i])
			return (false);
	}
	return (true);
}

bool bigint::operator!=(bigint rhs)
{
	return (!(*this == rhs));
}

std::ostream &operator<<(std::ostream &os, const bigint &src)
{
	for (int i = src.value.size() - 1; i >= 0; i--)
	{
		os << src.value[i];
	}
	return (os);
}