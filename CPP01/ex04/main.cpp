#include <iostream>
#include <fstream>
#include <string>
int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cerr << "Wrong number of args" << std::endl;
		return 1;
	}
	std::string to_find = av[2];
	std::string to_replace = av[3];
	std::string infile = av[1];
	std::ifstream input(infile.c_str());
	if(!input)
	{
		std::cerr << "Error, cannot open file" << std::endl;
		return 1;
	}
	std::string outfile = infile + ".replace";
	std::ofstream output(outfile.c_str());
	if(!output)
	{
		std::cerr << "Cannot create or access file" << std::endl;
		return 1;
	}
	std::string content;
	for(char c;input.get(c);content += c);
	std::string final;
	size_t pos = 0;
	size_t found = 0;
	for(;(found = content.find(to_find, pos)) != std::string::npos;pos = found + to_find.length())
	{
		final += content.substr(pos, found - pos);
		final += to_replace;
	}
	final += content.substr(pos);
	output << final;
}