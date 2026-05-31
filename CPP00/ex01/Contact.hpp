#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
private:
	std::string nickname;
	std::string first_name;
	std::string last_name;
	std::string numero;
	std::string secret;

public:
	void setNickname(std::string value);
	std::string getNickname();
	void setFirstName(std::string value);
	std::string getFirstName();
	void setLastName(std::string value);
	std::string getLastName();
	void setNumero(std::string value);
	std::string getNumero();
	void setSecret(std::string value);
	std::string getSecret();
};

#endif