#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T> class Array
{
  private:
	T *_array;
	unsigned int _size;

  public:
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	Array &operator=(Array const &rhs);
	~Array();

	unsigned int size() const;
	T &operator[](unsigned int index);
};

# include "Array.tpp"

#endif