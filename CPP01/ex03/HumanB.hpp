#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB{
private:
	Weapon* weapon;
	std::string name;
public:
	void attack();
};

#endif