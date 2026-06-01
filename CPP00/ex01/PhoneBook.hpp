#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{

private:
	Contact contact[8];
	int numberContact;
	int current;

public:
	PhoneBook();
	void newContact();
	void search();
	void printer(std::string);
};

#endif