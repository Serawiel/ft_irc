#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T * tab, size_t const length, F f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(tab[i]);
	}
}

template <typename T>
void iter(T * tab, size_t const length, void (*f)(T const &))
{
	for (size_t i = 0; i < length; i++)
	{
		f(tab[i]);
	}
}

#endif