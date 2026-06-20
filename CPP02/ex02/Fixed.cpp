#include "Fixed.hpp"
#include <iostream>
#include <cmath>
const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value * (1 << _bits))
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt() const
{
	return (_value / (1<< _bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->_value = other._value;
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	_value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator!=(const Fixed& other) const
{
	if(this->_value != other._value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& other) const
{
	if(this->_value == other._value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
	if(this->_value >= other._value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
	if(this->_value <= other._value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& other) const
{
	if(this->_value < other._value)
		return true;
	return false;
}

bool Fixed::operator>(const Fixed& other) const
{
	if(this->_value > other._value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_value++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_value--;
	return tmp;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a > b)
		return a;
	return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a < b)
		return a;
	return b;
}