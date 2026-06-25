#include "Fixed.hpp"
#include <iostream>

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	Fixed::_value = 0;
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n)
{
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _value(n)
{
	std::cout << "float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "default destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
	std::cout << "copy constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	_value = raw;
}

float Fixed::toFloat()
{
	return static_cast<float>(_value);
}

int Fixed::toInt()
{
	return static_cast<int>(_value);
}