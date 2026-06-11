#include "Fixed.hpp"
#include <iostream>
const int _bits = 8;

Fixed::Fixed()
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "default destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy assignment operator called" << std::endl;
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	_value = raw;
}