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
			std::cout << std::setw(1) << str[i];
		std::cout << std::setw(1) << ".";
	}
	else
		std::cout << std::setw(10) << str;
	std::cout << "|";
}

void PhoneBook::search()
{

	std::cout << "     Index|first name| last name|  nickname|\n";
	for (int i = 0; i < numberContact + 1; i++)
	{
		std::cout << std::setw(10) << i << "|";
		this->printer(this->contact[i].getFirstName());
		this->printer(this->contact[i].getLastName());
		this->printer(this->contact[i].getNickname());
		std::cout << std::endl;
	}
	std::string buffer;

	while (std::cin)
	{
		std::cout << "Enter index of contact :";
		getline(std::cin, buffer);
		if(buffer.length() != 1 || buffer[0] - '0' < 0 || buffer[0] - '0' > numberContact)
			continue;
		else
			break ;
	}
	int nb = buffer[0] - '0';
	std::cout << 
	this->printer(this->contact[nb].getFirstName());
	std::cout << std::endl;
	this->printer(this->contact[nb].getLastName());
	std::cout << std::endl;
	this->printer(this->contact[nb].getNickname());
	std::cout << std::endl;
	this->printer(this->contact[nb].getNumero());
	std::cout << std::endl;
	this->printer(this->contact[nb].getSecret());
	std::cout << std::endl;
}