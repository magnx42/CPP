#include "HumanB.hpp"

HumanB::HumanB(std::string namestr) : name(namestr), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon &weap)
{
	weapon = &weap;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}