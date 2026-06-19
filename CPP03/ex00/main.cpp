#include "ClapTrap.hpp"

static void attack(ClapTrap& give, ClapTrap& take, int amount)
{
	give.attack(take.getName());
	take.takeDamage(amount);
}

int main()
{
	ClapTrap a("Survivor");
	ClapTrap b("Zombie");
	attack(a, b, 2);
	b.beRepaired(3);
	attack(b, a, 4);
	a.beRepaired(5);
	attack(a, b, 15);
	attack(b, a, 5);
}