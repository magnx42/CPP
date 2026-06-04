#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	type = str;
}

std::string Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string type_str)
{
	type = type_str;
}