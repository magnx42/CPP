#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _lifePoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _lifePoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap named constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if(this != &other)
	{
		_name = other._name;
		_lifePoint = other._lifePoint;
		_attackDamage = other._attackDamage;
		_energyPoint = other._energyPoint;
	}
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Default ClapTrap copy constructor called" << std::endl;
	if(this != &other)
		*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& name)
{
	if(_energyPoint <= 0 || _lifePoint <= 0)
	{
		if(_energyPoint <= 0)
			std::cout << "ClapTrap " << _name << " doesn't have an energy point for attack" << std::endl;
		else if (_lifePoint <= 0)
			std::cout << "ClapTrap " << _name << " have 0 HP he cant attack" << std::endl;
		return ;	
	}
	_energyPoint -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << name << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_lifePoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " have 0 HP he cant take damages" << std::endl;
		return ;
	}
	_lifePoint -= amount;
	std::cout << "ClapTrap " << _name << " take " << amount << " damages, currently have " << _lifePoint << " HP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energyPoint <= 0 || _lifePoint <= 0)
	{
		if(_energyPoint <= 0)
			std::cout << "ClapTrap " << _name << " doesn't have an energy point to be repaired" << std::endl;
		else if (_lifePoint <= 0)
			std::cout << "ClapTrap " << _name << " have 0 HP he cant be repaired" << std::endl;
		return ;	
	}
	_energyPoint -= 1;
	_lifePoint += amount;
	std::cout << "ClapTrap " << _name << " repaired " << amount << " HP, he curently have " << _lifePoint << " HP and " << _energyPoint << " energy points" << std::endl;
	return ;
}