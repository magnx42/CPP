#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	ClapTrap cp_marco("Marco");
	ClapTrap cp_anael("Anael");
	cp_marco.attack("Anael");
	cp_anael.takeDamage(5);
	cp_anael.beRepaired(15);
	ScavTrap cp_enzo("Enzo");
	ScavTrap cp_matis("Matis");
	cp_matis.attack("Enzo");
	cp_enzo.takeDamage(5);
	cp_anael.beRepaired(15);
}