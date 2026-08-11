#include "iter.hpp"
#include <iostream>

int main()
{
    std::cout << "=== non const int tab ===" << std::endl;
    int tab[5] = {1, 2, 3, 4, 5};
    for(int i = 0;i<5;i++)
        std::cout << tab[i];
    std::cout << std::endl;
    ::iter(tab, 5, ::moreone<int>);
    for(int i = 0;i<5;i++)
        std::cout << tab[i];
    std::cout << std::endl;

    std::cout << std::endl << "=== const int tab ===" << std::endl;
    const int tab2[5] = {1, 2, 3, 4, 5};
    ::iter(tab2, 5, ::display<int>);
    std::cout << std::endl;

    std::cout << std::endl << "=== non const char tab ===" << std::endl;
    char str[6] = {'s', 'a', 'l', 'u', 't', '\0'};
    std::cout << "before: " << str << std::endl;
    ::iter(str, 5, ::moreone<char>);
    std::cout << "after: " << str << std::endl;

    std::cout << std::endl << "=== const char tab ===" << std::endl;
    const char str2[6] = {'s', 'a', 'l', 'u', 't', '\0'};
    ::iter(str2, 5, ::display<char>);

    std::cout << std::endl << "=== const string tab ===" << std::endl;
    const std::string str4[] = {"salut", "tu", "vas", "bien"};
    ::iter(str4, 5, ::display<std::string>);
}