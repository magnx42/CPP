#include "Harl.hpp"
#include <string>

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }
    Harl h;
    h.complain(av[1]);
    return 0;
}