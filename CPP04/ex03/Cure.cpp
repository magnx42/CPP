#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(const Cure& other)
{
	this->_type = other._type;
}

Cure& Cure::operator=(const Cure& other)
{
	if(this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Cure::~Cure()
{
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}