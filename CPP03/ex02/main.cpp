#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	cp_enzo.takeDamage(5);
	cp_enzo.beRepaired(15);

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
	antoine.beRepaired(10);
	antoine.highFivesGuys();

	std::cout << "=== FragTrap energy depletion ===" << std::endl;
	for (int i = 0; i < 101; i++)
		sam.attack("antoine");

	std::cout << "=== FragTrap life depletion ===" << std::endl;
	fr_default.takeDamage(200);
	fr_default.attack("sam");
	fr_default.highFivesGuys();

	std::cout << "=== End of scope ===" << std::endl;
	return 0;
}
