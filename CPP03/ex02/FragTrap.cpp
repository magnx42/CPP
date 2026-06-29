#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_lifePoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_lifePoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap named constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "Default FragTrap copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "Default FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if(_name.empty())
		std::cout << "FragTrap want a high five" << std::endl;
	else
		std::cout << "FragTrap " << _name << " want a high five" << std::endl;
}