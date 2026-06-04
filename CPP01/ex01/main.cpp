#include "Zombie.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "The program must take only one argument in parameter" << std::endl;
		return 1;
	}
	int n;
	std::stringstream ss(av[1]);
	ss >> n;
	if(ss.fail() == 1 || n <= 0)
	{
		std::cerr << "Wrong argument" << std::endl;
		return 1;
	}
	Zombie *z = zombieHorde(n, "Foo");
	for(int i = 0;i < n;i++)
		z[i].announce();
	delete[] z;
}