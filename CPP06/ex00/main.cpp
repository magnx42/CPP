#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
        return std::cerr << "Program must have 1 arg" << std::endl, 1;
    ScalarConverter::convert(av[1]);
}