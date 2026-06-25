#include "ClapTrap.hpp"

int main()
{
	ClapTrap cp_marco("Marco");
	ClapTrap cp_anael("Anael");
	cp_marco.attack("Anael");
	cp_anael.takeDamage(5);
	cp_anael.beRepaired(15);
}