#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO" << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string name[4] =  {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    for (;i < 4 && name[i] != level;i++);
    if(i < 4 && name[i] == level)
        (this->*function[i])();
}