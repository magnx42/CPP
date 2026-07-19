#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(const Ice& other)
{
	this->_type = other._type;
}

Ice& Ice::operator=(const Ice& other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Ice::~Ice()
{
}
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
}