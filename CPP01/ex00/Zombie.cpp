#include "Zombie.hpp"

Zombie::Zombie(std::string name_z) : name(name_z)
{
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroy" << std::endl;
}