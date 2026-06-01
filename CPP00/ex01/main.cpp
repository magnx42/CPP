#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
int main()
{
	PhoneBook pb;
	std::string buffer;
	while (std::cin)
	{
		std::cout << "Enter SEARCH, ADD or EXIT :";
		getline(std::cin, buffer);

		if (buffer == "SEARCH\0")
			pb.search();
		else if (buffer == "ADD\0")
			pb.newContact();
		else if (buffer == "EXIT\0")
			break;
	}
}