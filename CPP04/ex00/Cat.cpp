#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Default cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Default cat operator assignation called" << std::endl;
	if(this != &other)
		this->_type = other._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Default cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}