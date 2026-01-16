#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector()
{
}

PmergeMeVector::~PmergeMeVector()
{
}

PmergeMeVector::PmergeMeVector(PmergeMeVector const &src)
{
	(void)src;
}

PmergeMeVector const &PmergeMeVector::operator=(PmergeMeVector const &src)
{
	(void)src;
	return (*this);
}

std::vector<size_t> PmergeMeVector::generateJacobsthal(size_t pendSize)
{
	if (pendSize == 0)
		return (std::vector<size_t>());
	std::vector<size_t> jacobsthal;
	size_t	a = 0, b = 1, next;
	while ((next = b + 2 * a) <= pendSize)
	{
		if (next > 1)
			jacobsthal.push_back(next);
		a = b;
		b = next;
	}
	std::vector<size_t> order;
	size_t	previousPush = 1;
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		for (size_t k = jacobsthal[i]; k > previousPush; k--)
			order.push_back(k);
		previousPush = jacobsthal[i];
	}
	for (size_t k = previousPush + 1; k <= pendSize; k++)
		order.push_back(k);
	return (order);
}

std::vector<int> PmergeMeVector::mergeInsertSort(std::vector<int> input)
{
	if (input.size() <= 1)
		return (input);
	std::vector< std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int large = std::max(input[i], input[i + 1]);
		int small = std::min(input[i], input[i + 1]);
		pairs.push_back(std::make_pair(large, small));
	}
	if (input.size() % 2 == 1)
	{
		straggler = input[input.size() - 1];
		hasStraggler = true;
	}
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
	}
	std::vector<int> sortedMain = mergeInsertSort(mainChain);
	std::vector< std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < sortedMain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedMain[i])
			{
				sortedPairs.push_back(pairs[j]);
				break ;
			}
		}
	}
	std::vector<int> pend;
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		pend.push_back(sortedPairs[i].second);
	}
	if (hasStraggler)
	{
		pend.push_back(straggler);
	}
	std::vector<size_t> insertionOrder = generateJacobsthal(pend.size());
	std::vector<int>::iterator pos = std::lower_bound(sortedMain.begin(), sortedMain.end(), pend[0]);
	sortedMain.insert(pos, pend[0]);
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		size_t pendIndex = insertionOrder[i] - 1;
		pos = std::lower_bound(sortedMain.begin(), sortedMain.end(), pend[pendIndex]);
		sortedMain.insert(pos, pend[pendIndex]);
	}
	return (sortedMain);
}

std::vector<int> PmergeMeVector::sort(int argc, char **argv)
{
	int		value;
	char	c;

	std::vector<int> numbers;
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> value))
			throw ErrorException();
		if (iss >> c)
			throw ErrorException();
		if (value <= 0)
			throw ErrorException();
		for (unsigned int j = 0; j < numbers.size(); j++)
		{
			if (value == numbers[j])
				throw ErrorException();
		}
		numbers.push_back(value);
	}
	if (numbers.empty())
		throw ErrorException();
	numbers = mergeInsertSort(numbers);
	return (numbers);
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it < vec.end(); it++)
	{
		os << " " << *it;
	}
	return (os);
}

std::ostream &operator<<(std::ostream &os, const std::deque<int> &vec)
{
	for (std::deque<int>::const_iterator it = vec.begin(); it < vec.end(); it++)
	{
		os << " " << *it;
	}
	return (os);
}

const char *ErrorException::what() const throw()
{
	return ("Error");
}


PmergeMeDeque::PmergeMeDeque()
{
}

PmergeMeDeque::~PmergeMeDeque()
{
}

PmergeMeDeque::PmergeMeDeque(PmergeMeDeque const &src)
{
	(void)src;
}

PmergeMeDeque const &PmergeMeDeque::operator=(PmergeMeDeque const &src)
{
	(void)src;
	return (*this);
}

std::deque<size_t> PmergeMeDeque::generateJacobsthal(size_t pendSize)
{
	if (pendSize == 0)
		return (std::deque<size_t>());
	std::deque<size_t> jacobsthal;
	size_t	a = 0, b = 1, next;
	while ((next = b + 2 * a) <= pendSize)
	{
		if (next > 1)
			jacobsthal.push_back(next);
		a = b;
		b = next;
	}
	std::deque<size_t> order;
	size_t	previousPush = 1;
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		for (size_t k = jacobsthal[i]; k > previousPush; k--)
			order.push_back(k);
		previousPush = jacobsthal[i];
	}
	for (size_t k = previousPush + 1; k <= pendSize; k++)
		order.push_back(k);
	return (order);
}

std::deque<int> PmergeMeDeque::mergeInsertSort(std::deque<int> input)
{
	if (input.size() <= 1)
		return (input);
	std::deque< std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int large = std::max(input[i], input[i + 1]);
		int small = std::min(input[i], input[i + 1]);
		pairs.push_back(std::make_pair(large, small));
	}
	if (input.size() % 2 == 1)
	{
		straggler = input[input.size() - 1];
		hasStraggler = true;
	}
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
	}
	std::deque<int> sortedMain = mergeInsertSort(mainChain);
	std::deque< std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < sortedMain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedMain[i])
			{
				sortedPairs.push_back(pairs[j]);
				break ;
			}
		}
	}
	std::deque<int> pend;
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		pend.push_back(sortedPairs[i].second);
	}
	if (hasStraggler)
	{
		pend.push_back(straggler);
	}
	std::deque<size_t> insertionOrder = generateJacobsthal(pend.size());
	std::deque<int>::iterator pos = std::lower_bound(sortedMain.begin(), sortedMain.end(), pend[0]);
	sortedMain.insert(pos, pend[0]);
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		size_t pendIndex = insertionOrder[i] - 1;
		pos = std::lower_bound(sortedMain.begin(), sortedMain.end(), pend[pendIndex]);
		sortedMain.insert(pos, pend[pendIndex]);
	}
	return (sortedMain);
}

std::deque<int> PmergeMeDeque::sort(int argc, char **argv)
{
	int		value;
	char	c;

	std::deque<int> numbers;
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		if (!(iss >> value))
			throw ErrorException();
		if (iss >> c)
			throw ErrorException();
		if (value <= 0)
			throw ErrorException();
		for (unsigned int j = 0; j < numbers.size(); j++)
		{
			if (value == numbers[j])
				throw ErrorException();
		}
		numbers.push_back(value);
	}
	if (numbers.empty())
		throw ErrorException();
	numbers = mergeInsertSort(numbers);
	return (numbers);
}