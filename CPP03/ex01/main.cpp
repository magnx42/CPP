#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	cp_matis.attack("Enzo");
	cp_enzo.takeDamage(5);
	cp_enzo.beRepaired(15);
	cp_enzo.guardGate();

	std::cout << "=== ScavTrap energy depletion ===" << std::endl;
	for (int i = 0; i < 11; i++)
		cp_matis.attack("Enzo");

	std::cout << "=== ScavTrap life depletion ===" << std::endl;
	sc_default.takeDamage(200);
	sc_default.attack("Matis");
	sc_default.beRepaired(10);

	std::cout << "=== End of scope ===" << std::endl;
	return 0;
}
