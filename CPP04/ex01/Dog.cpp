#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain;
	std::cout << "Default dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Default dog copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Default dog operator assignation called" << std::endl;
	if(this != &other)
	{
		this->_type = other._type;
		*this->_brain = *other._brain;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Default dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf" << std::endl;
}

std::string Dog::getIdea(int index)const
{
	return _brain->getIdea(index);
}

void Dog::setIdea(int index, std::string str)
{
	_brain->setIdea(index, str);
}