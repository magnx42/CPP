#include "Base.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    srand(time(NULL));
    Base *baseTest = generate();
    C c;
    Base &referenceTest = c;
    identify(baseTest);
    identify(referenceTest);
    delete baseTest;
    for (int i = 0; i < 10; i++)
    {
        Base *lst = generate();
        identify(lst);
        delete lst;
    }
}