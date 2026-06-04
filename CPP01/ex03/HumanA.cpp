#include "HumanA.hpp"

HumanA::HumanA(std::string name_str, Weapon weap)
{
	name = name_str;
	weapon = weap;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType();
}