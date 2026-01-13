#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <climits>
# include <exception>
# include <iostream>
# include <vector>

class OutOfSizemaxException : public std::exception
{
  public:
	virtual const char *what() const throw();
};

class NotEnoughNumbersException : public std::exception
{
  public:
	virtual const char *what() const throw();
};

class Span
{
  private:
	std::vector<int> v;
	unsigned int _sizemax;

  public:
	Span();
	Span(unsigned int N);
	Span(Span const &src);
	Span const &operator=(Span const &rhs);
	~Span();

	void addNumber(int nb);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	template <typename T>
	void addRange(T begin, T end)
	{
		size_t count = std::distance(begin, end);
		if (v.size() + count > _sizemax)
			throw OutOfSizemaxException();
		v.insert(v.end(), begin, end);
	}
	void display() const;
};

#endif