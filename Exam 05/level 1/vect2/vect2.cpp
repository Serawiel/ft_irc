#include "vect2.hpp"

vect2::vect2()
{
	v.push_back(0);
	v.push_back(0);
}

vect2::vect2(int x, int y)
{
	v.push_back(x);
	v.push_back(y);
}

vect2::vect2(vect2 const &src)
{
	this->v = src.v;
}

vect2 const &vect2::operator=(vect2 const &rhs)
{
	if (this->v != rhs.v)
	{
		this->v = rhs.v;
	}
	return (*this);
}

vect2::~vect2()
{
}

int &vect2::operator[](int a)
{
	return (v[a]);
}

int const &vect2::operator[](int a) const
{
	return (v[a]);
}

vect2 &vect2::operator++()
{
	v[0]++;
	v[1]++;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 temp(*this);
	v[0]++;
	v[1]++;
	return (temp);
}

vect2 &vect2::operator--()
{
	v[0]--;
	v[1]--;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	v[0]--;
	v[1]--;
	return (temp);
}

vect2 &vect2::operator+=(vect2 const &rhs)
{
	v[0] = v[0] + rhs.v[0];
	v[1] = v[1] + rhs.v[1];
	return (*this);
}

vect2 &vect2::operator-=(vect2 const &rhs)
{
	v[0] = v[0] - rhs.v[0];
	v[1] = v[1] - rhs.v[1];
	return (*this);
}

vect2 &vect2::operator*=(int nb)
{
	v[0] = v[0] * nb;
	v[1] = v[1] * nb;
	return (*this);
}

vect2 vect2::operator+(vect2 const &rhs) const
{
	vect2 result(*this);
	result += rhs;
	return (result);
}

vect2 vect2::operator-(vect2 const &rhs) const
{
	vect2 result(*this);
	result -= rhs;
	return (result);
}

vect2 vect2::operator*(int nb) const
{
	vect2	result;
	result.v[0] = v[0] * nb;
	result.v[1] = v[1] * nb;
	return (result);
}

vect2 operator*(int nb, vect2 const& rhs)
{
	return (rhs * nb);
}

std::ostream &operator<<(std::ostream &os, vect2 const &rhs)
{
	os << "{" << rhs.v[0] << ", " << rhs.v[1] << "}";
	return (os);
}