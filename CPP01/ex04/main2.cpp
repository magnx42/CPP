#include <iostream>
#include <cstring>
#include <fstream>

int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cerr << "Error wrong number of args" << std::endl;
		return 1;
	}
	std::string infile = av[1];
	std::string outfile = infile + ".replace";
	std::string to_find = av[2];
	std::string to_replace = av[3];
	std::string content;
	std::string final;
	std::ifstream input(infile.c_str());
	if(!input)
	{
		std::cerr << "Error access infile" << std::endl;
		return 1;
	}
	std::ofstream output(outfile.c_str());
	if(!output)
	{
		std::cerr << "Error access or create file" << std::endl;
		return 1;
	}
	for(char c;input.get(c);content += c);
	
}