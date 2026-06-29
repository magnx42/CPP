#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_lifePoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	_lifePoint = 100;
	_energyPoint = 50;
	_attackDamage = 30;
	_name = ClapTrap::_name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "Default DiamondTrap named constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_lifePoint = other._lifePoint;
		_attackDamage = other._attackDamage;
		_energyPoint = other._energyPoint;
	}
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "Default DiamondTrap copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Default DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << _name << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}