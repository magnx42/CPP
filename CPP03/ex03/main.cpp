#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap default constructor ===" << std::endl;
	ClapTrap cp_default;

	std::cout << "=== ClapTrap named constructor ===" << std::endl;
	ClapTrap cp_marco("Marco");
	ClapTrap cp_anael("Anael");

	std::cout << "=== ClapTrap copy constructor ===" << std::endl;
	ClapTrap cp_copy(cp_marco);

	std::cout << "=== ClapTrap assignment operator ===" << std::endl;
	ClapTrap cp_assign;
	cp_assign = cp_anael;

	std::cout << "=== ClapTrap actions ===" << std::endl;
	cp_marco.attack("Anael");
	cp_anael.takeDamage(5);
	cp_anael.beRepaired(15);

	std::cout << "=== ScavTrap default constructor ===" << std::endl;
	ScavTrap sc_default;

	std::cout << "=== ScavTrap named constructor ===" << std::endl;
	ScavTrap cp_enzo("Enzo");
	ScavTrap cp_matis("Matis");

	std::cout << "=== ScavTrap copy constructor ===" << std::endl;
	ScavTrap sc_copy(cp_enzo);

	std::cout << "=== ScavTrap assignment operator ===" << std::endl;
	ScavTrap sc_assign;
	sc_assign = cp_matis;

	std::cout << "=== ScavTrap actions ===" << std::endl;
	cp_enzo.guardGate();
	cp_matis.attack("Enzo");
	cp_matis.takeDamage(12);

	std::cout << "=== FragTrap default constructor ===" << std::endl;
	FragTrap fr_default;

	std::cout << "=== FragTrap named constructor ===" << std::endl;
	FragTrap sam("sam");
	FragTrap antoine("antoine");

	std::cout << "=== FragTrap copy constructor ===" << std::endl;
	FragTrap fr_copy(sam);

	std::cout << "=== FragTrap assignment operator ===" << std::endl;
	FragTrap fr_assign;
	fr_assign = antoine;

	std::cout << "=== FragTrap actions ===" << std::endl;
	sam.attack("antoine");
	antoine.takeDamage(19);
	antoine.highFivesGuys();

	std::cout << "=== DiamondTrap default constructor ===" << std::endl;
	DiamondTrap di_default;

	std::cout << "=== DiamondTrap named constructor ===" << std::endl;
	DiamondTrap joel("joel");

	std::cout << "=== DiamondTrap copy constructor ===" << std::endl;
	DiamondTrap di_copy(joel);

	std::cout << "=== DiamondTrap assignment operator ===" << std::endl;
	DiamondTrap di_assign;
	di_assign = joel;

	std::cout << "=== DiamondTrap actions ===" << std::endl;
	joel.whoAmI();
	joel.attack("Matis");
	joel.takeDamage(30);
	joel.beRepaired(10);
	joel.guardGate();
	joel.highFivesGuys();

	std::cout << "=== End of scope ===" << std::endl;
	return 0;
}
