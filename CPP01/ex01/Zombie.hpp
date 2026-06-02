#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>
#include <sstream>


class Zombie {
private:
	std::string name;
public:
	Zombie();
	void announce();
	void setName(std::string name_z);
	~Zombie();
};

Zombie *zombieHorde(int n, std::string name);

#endif