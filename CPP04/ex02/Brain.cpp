#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Default Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Default Brain assignation called" << std::endl;
	if(this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Default Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index)const
{
	if(index < 0 || index >= 100)
		return std::cout << "Index must be between 0 and 99" << std::endl, "";
	return this->_ideas[index];
}

void Brain::setIdea(int index, std::string str)
{
	if(index < 0 || index >= 100)
	{
		std::cout << "Index must be between 0 and 99" << std::endl;
		return ;
	}
	this->_ideas[index] = str;
}