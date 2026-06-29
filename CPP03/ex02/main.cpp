#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
	ClapTrap cp_marco("Marco");
	ClapTrap cp_anael("Anael");
	cp_marco.attack("Anael");
	cp_anael.takeDamage(5);
	cp_anael.beRepaired(15);
	ScavTrap cp_enzo("Enzo");
	ScavTrap cp_matis("Matis");
	cp_enzo.guardGate();
	cp_matis.attack("Enzo");
	cp_anael.beRepaired(15);
	FragTrap sam("sam");
	FragTrap antoine("antoine");
	sam.attack("antoine");
	antoine.takeDamage(19);
	antoine.highFivesGuys();
}