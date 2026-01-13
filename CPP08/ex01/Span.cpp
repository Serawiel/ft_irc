#include "Span.hpp"

Span::Span() : v(), _sizemax(0)
{
}

Span::Span(unsigned int N) : v(), _sizemax(N)
{
}

Span::Span(Span const &src) : v(src.v), _sizemax(src._sizemax)
{
}

Span const &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_sizemax = rhs._sizemax;
		v = rhs.v;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{
	if (v.size() < _sizemax)
		this->v.push_back(nb);
	else
		throw OutOfSizemaxException();
}

unsigned int Span::shortestSpan() const
{
	if (v.size() < 2)
	{
		throw NotEnoughNumbersException();
	}
	std::vector<int> sorted = this->v;
	std::sort(sorted.begin(), sorted.end());
	unsigned int min = UINT_MAX;
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		unsigned int diff = sorted[i + 1] - sorted[i];
		if (diff < min)
			min = diff;
	}
	return (min);
}

unsigned int Span::longestSpan() const
{
	if (v.size() < 2)
	{
		throw NotEnoughNumbersException();
	}
	std::vector<int> sorted = this->v;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

void Span::display() const
{
	std::cout << "Span content: ";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Size: " << v.size() << "/" << _sizemax << std::endl;
}

const char *OutOfSizemaxException::what() const throw()
{
	return ("Span is already or will be full !");
}

const char *NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in span !");
}
