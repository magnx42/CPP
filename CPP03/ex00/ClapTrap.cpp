#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_hitPoints = other._hitPoints;
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_hitPoints = other._hitPoints;
	}
	std::cout << "ClapTrap Copy assignement operator called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& name)
{
	if(_energyPoints <= 0 || _hitPoints <= 0)
	{
		if(_energyPoints <= 0)
			std::cout << "cannot attack because the amount of energy is insufficient" << std::endl;
		else
			std::cout <<  "cannot attack because " << _name << " is dead" << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << name << ", causing " << _attackDamage << " points of damage and currently have " << _energyPoints << " energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints <= 0)
	{
		std::cout <<  "cannot take damage because " << _name << " is dead" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if(_hitPoints >= 0)
		std::cout << "ClapTrap " << _name << " took " << amount << " damage, it currently has " << _hitPoints << " HP" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " took " << amount << " damage, it currently has 0 HP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energyPoints <= 0 || _hitPoints <= 0)
	{
		if(_energyPoints <= 0)
			std::cout << "cannot repair because the amount of energy is insufficient" << std::endl;
		else
			std::cout <<  "cannot repair because " << _name << " is dead" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	if(_hitPoints >= 0)
		std::cout << "ClapTrap " << _name << " repaired " << amount << "HP, it currently has " << _hitPoints << " HP and currently have " << _energyPoints << " energy" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " repaired " << amount << "HP, it currently has 0 HP and currently have " << _energyPoints << " energy" << std::endl;
}

std::string ClapTrap::getName() const
{
	return _name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor " << _name << " called" << std::endl;
}