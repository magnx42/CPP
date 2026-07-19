#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Default WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Default WrongCat operator assignation called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrongcat Meow" << std::endl;
}