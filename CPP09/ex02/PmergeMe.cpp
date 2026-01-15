#include "PmergeMe.hpp"

void PmergeMeVector::createPairs(std::string const &str)
{
	std::istringstream iss(str);
	int first, second;
	while (iss >> first)
	{
		if (first <= 0)
			throw ErrorException();
		if (iss >> second)
		{
			if (second <= 0)
				throw ErrorException();
			Pair p;
			if (first >= second)
			{
				p.large = first;
				p.small = second;
			}
			else
			{
				p.large = second;
				p.small = first;
			}
			_pairs.push_back(p);
		}
		else
		{
			_aloneNb = first;
			_hasAloneNb = true;
		}
	}
	if (_pairs.empty() && !_hasAloneNb)
		throw ErrorException();
}

void PmergeMeVector::sortLarger()
{
	
}

const char *ErrorException::what() const throw()
{
	return ("Error");
}