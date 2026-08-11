#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base::~Base()
{
    // std::cout << "Default virtual Base destructor called" << std::endl;
}

Base *generate()
{
    switch(rand() % 3)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Error: unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &)
    {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::exception &)
    {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception &)
    {}
}