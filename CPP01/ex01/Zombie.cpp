#include "Zombie.hpp"

Zombie::Zombie()
{
	//zombie created
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name_z)
{
	name = name_z;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroy" << std::endl;
}