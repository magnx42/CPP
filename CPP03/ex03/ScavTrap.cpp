#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_lifePoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_lifePoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "Default ScavTrap named constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "Default ScavTrap copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Default ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &name)
{
	if (_energyPoint <= 0 || _lifePoint <= 0)
	{
		if (_energyPoint <= 0)
			std::cout << "ScavTrap " << _name << " doesn't have an energy point for attack" << std::endl;
		else if (_lifePoint <= 0)
			std::cout << "ScavTrap " << _name << " have 0 HP he cant attack" << std::endl;
		return;
	}
	_energyPoint -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << name << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if(!_name.empty())
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}