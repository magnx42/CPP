#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	numberContact = 0;
	current = 0;
}

void PhoneBook::newContact()
{
	std::string buffer;
	std::cout << "Enter first name :";
	std::getline(std::cin, buffer);
	contact[current].setFirstName(buffer);
	std::cout << "Enter last name :";
	std::getline(std::cin, buffer);
	contact[current].setLastName(buffer);
	std::cout << "Enter nickname :";
	std::getline(std::cin, buffer);
	contact[current].setNickname(buffer);
	std::cout << "Enter phone number :";
	std::getline(std::cin, buffer);
	contact[current].setNumero(buffer);
	std::cout << "Enter darkest secret :";
	std::getline(std::cin, buffer);
	contact[current].setSecret(buffer);
}

void PhoneBook::search()
{
	std::cout << "     Index|first name| last name|";
	for(int i = 0;i<numberContact;i++)
	{

	}
}