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

void PhoneBook::printer(std::string str)
{
	if (str.length() >= 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << std::setw(9) << str[i];
		std::cout << std::setw(1) << ".";
	}
	else
		std::cout << std::setw(10);
	std::cout << "|";
}

void PhoneBook::search()
{

	std::cout << "     Index|first name| last name|  nickname|\n";
	for (int i = 0; i < numberContact; i++)
	{
		std::cout << i;
		this->printer(this->contact->getFirstName());
		this->printer(this->contact->getLastName());
		this->printer(this->contact->getNickname());
	}
	std::string buffer;
	do
	{
		std::cout << "Enter index of contact :";
		getline(std::cin, buffer);
	} while (std::cin || buffer[0] == '\0' || (buffer[0] - '0' < 0 && buffer[0] - '0' > numberContact) || buffer.length() != 1);
	int nb = buffer[0] - '0';
	std::cout << nb << "|";
	this->printer(this->contact->getFirstName());
	this->printer(this->contact->getLastName());
	this->printer(this->contact->getNickname());
	this->printer(this->contact->getNumero());
	this->printer(this->contact->getSecret());
}