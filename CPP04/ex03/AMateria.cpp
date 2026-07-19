#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("No type")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return *this;
}

AMateria::AMateria(const AMateria& other)
{
	this->_type = other._type;
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}