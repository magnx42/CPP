#include <iostream>
#include <string>
int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* brainPTR = &brain;
	std::string& brainREF = brain;
	
	std::cout << &brain << std::endl;
	std::cout << brainPTR << std::endl;
	std::cout << &brainREF << std::endl;

	std::cout << brain << std::endl;
	std::cout << *brainPTR << std::endl;
	std::cout << brainREF << std::endl;
}