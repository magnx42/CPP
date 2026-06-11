#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	numberContact = 0;
	current = 0;
}

std::string PhoneBook::setContactInfo(std::string str)
{
	std::string buffer;
	while (std::cin)
	{
		std::cout << str;
		getline(std::cin, buffer);
		if (buffer.length() == 0)
			continue;
		else
			return str;
	}
	return "";
}

void PhoneBook::newContact()
{
	if (current == 7)
		current = 0;
	PhoneBook::setContactInfo("Enter first name :");
	contact[current].setFirstName(PhoneBook::setContactInfo("Enter first name :"));
	contact[current].setLastName(PhoneBook::setContactInfo("Enter last name :"));
	contact[current].setNickname(PhoneBook::setContactInfo("Enter nickname :"));
	contact[current].setNumero(PhoneBook::setContactInfo("Enter phone number :"));
	contact[current].setSecret(PhoneBook::setContactInfo("Enter darkest secret :"));
	if (numberContact < 8)
		numberContact++;
	current++;
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
	if (numberContact == 0)
		return;
	for (int i = 0; i < numberContact; i++)
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
		if (buffer.length() != 1 || buffer[0] - '0' < 0 || buffer[0] - '0' > numberContact)
			continue;
		else
			break;
	}
	int nb = buffer[0] - '0';
	std::cout << "First name :" << this->contact[nb].getFirstName() << std::endl;
	std::cout << "Last name :" << this->contact[nb].getLastName() << std::endl;
	std::cout << "Nickname :" << this->contact[nb].getNickname() << std::endl;
	std::cout << "Numero :" << this->contact[nb].getNumero() << std::endl;
	std::cout << "Darkest secret :" << this->contact[nb].getSecret() << std::endl;
}
