#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <vector>

class vect2
{
  public:
	std::vector<int> v;

	vect2();
	vect2(int x, int y);
	vect2(vect2 const & src);
	vect2 const & operator=(vect2 const & rhs);
	~vect2();
	int & operator[](int a);
	int const & operator[](int a) const;

	vect2 & operator++();
	vect2 operator++(int);
	vect2 & operator--();
	vect2 operator--(int);

	vect2 & operator+=(vect2 const & rhs);
	vect2 & operator-=(vect2 const & rhs);
	vect2 & operator*=(int nb);
	vect2 operator+(vect2 const & rhs) const;
	vect2 operator-(vect2 const & rhs) const;
	vect2 operator*(int nb) const;
};

vect2 operator*(int nb, vect2 const & rhs);
std::ostream & operator<<(std::ostream &os, vect2 const & rhs);

#endif