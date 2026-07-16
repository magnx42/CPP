#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Default constructor ===" << std::endl;
	ClapTrap cp_default;

	std::cout << "=== Named constructor ===" << std::endl;
	ClapTrap cp_marco("Marco");
	ClapTrap cp_anael("Anael");

	std::cout << "=== Copy constructor ===" << std::endl;
	ClapTrap cp_copy(cp_marco);

	std::cout << "=== Assignment operator ===" << std::endl;
	ClapTrap cp_assign;
	cp_assign = cp_anael;

	std::cout << "=== Basic actions ===" << std::endl;
	cp_marco.attack("Anael");
	cp_anael.takeDamage(5);
	cp_anael.beRepaired(15);

	std::cout << "=== Energy depletion ===" << std::endl;
	for (int i = 0; i < 11; i++)
		cp_marco.attack("Anael");

	std::cout << "=== Life depletion ===" << std::endl;
	cp_default.takeDamage(20);
	cp_default.attack("Marco");
	cp_default.takeDamage(5);
	cp_default.beRepaired(5);

	std::cout << "=== End of scope ===" << std::endl;
	return 0;
}
