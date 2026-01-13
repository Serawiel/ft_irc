#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>

class NotFoundException : public std::exception
{
  public:
	virtual const char *what() const throw();
};

template <typename T> typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(),
			value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

# include "easyfind.tpp"

#endif