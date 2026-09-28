#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
int main()
{
    std::cout << "=== Should find 5 in the list and display 5 ===" << std::endl;
    try
    {
        std::vector<int> v;
        int tab[] = {1, 5, 4, 7, 2, 9, 6};
        for(int i = 0; i < 7;i++)
            v.push_back(tab[i]);
        std::vector<int>::const_iterator it = easyfind(v, 5);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl << "=== Should not find the index and display error ===" << std::endl;
    try
    {
        std::vector<int> v;
        int tab[] = {1, 5, 4, 7, 2, 9, 6};
        for(int i = 0; i < 7;i++)
            v.push_back(tab[i]);
        std::vector<int>::const_iterator it = easyfind(v, 34);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Const arg, should find the index and display it ===" << std::endl;
    try
    {
        std::vector<int> v;
        int tab[] = {1, 5, 4, 7, 2, 9, 6};
        for(int i = 0; i < 7;i++)
            v.push_back(tab[i]);
        const std::vector<int> v_const = static_cast<const std::vector<int> >(v);
        std::vector<int>::const_iterator it = easyfind(v_const, 5);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== List arg, should find the index and display it ===" << std::endl;
    try
    {
        std::list<int> lst;
        int tab[] = {1, 5, 4, 7, 2, 9, 6};
        for(int i = 0; i < 7;i++)
            lst.push_back(tab[i]);
        std::list<int>::const_iterator it = easyfind(lst, 7);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Empty vector, should not find any index and display error ===" << std::endl;
    try
    {
        std::vector<int> v;
        std::vector<int>::const_iterator it = easyfind(v, 34);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}