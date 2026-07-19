#include "Cat.hpp"
#include "Brain.hpp"
Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain;
	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Default cat copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Default cat operator assignation called" << std::endl;
	if(this != &other)
	{
		*this->_brain = *other._brain;
		this->_type = other._type;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Default cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string Cat::getIdea(int index)const
{
	return _brain->getIdea(index);
}

void Cat::setIdea(int index, std::string str)
{
	_brain->setIdea(index, str);
}