#include "Contact.hpp"

std::string Contact::getFirstName()
{
	return first_name;
}

void Contact::setFirstName(std::string value)
{
	first_name = value;
}

std::string Contact::getLastName()
{
	return last_name;
}

void Contact::setLastName(std::string value)
{
	last_name = value;
}
std::string Contact::getNickname()
{
	return nickname;
}

void Contact::setNickname(std::string value)
{
	nickname = value;
}

std::string Contact::getNumero()
{
	return numero;
}

void Contact::setNumero(std::string value)
{
	numero = value;
}

std::string Contact::getSecret()
{
	return secret;
}

void Contact::setSecret(std::string value)
{
	secret = value;
}
