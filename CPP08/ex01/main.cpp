#include "Span.hpp"
#include <iostream>
#include <cstdlib>
static void display_vec(std::vector<int> &v)
{
    for(std::vector<int>::iterator it = v.begin();it != v.end();)
    {
        std::cout << *it;
        it++;
        if(it != v.end())
            std::cout << " | ";
    }
}

int main()
{
    srand(time(NULL));
    std::cout << "=== Subject main, should display 2 then 14" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

    std::cout << std::endl << "=== Should display min 11 and max 66 ===" << std::endl;
    try
    {
        Span test(5);
        int tab[] = {34, 54, 65, 12, 78};
        for(int i = 0;i < 5;i++)
            test.addNumber(tab[i]);
        std::cout << "min: " << test.shortestSpan() << std::endl << "max: " << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Should join 2 vector int one ===" << std::endl;
    try
    {
        Span test(30);
        std::vector<int> vectest;
        int tab[] = {34, 54, 65, 12, 78};
        int tab2[] = {4, 2, 1, 6, 7};
        for(int i = 0;i < 5;i++)
            test.addNumber(tab[i]);
        for(int i = 0;i < 5;i++)
            vectest.push_back(tab2[i]);
        std::cout << "first vector list: ";
        test.display_vec();
        std::cout << std::endl << "second vector list: ";
        display_vec(vectest);
        test.addRange(vectest.begin(), vectest.end());
        std::cout << std::endl << "after join: ";
        test.display_vec();
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Should display an error cause second vector reach max number of elements ===" << std::endl;
    try
    {
        Span test(30);
        std::vector<int> vectest;
        int tab[] = {34, 54, 65, 12, 78};
        for(int i = 0;i < 5;i++)
            test.addNumber(tab[i]);
        for(int i = 0;i < 100;i++)
            vectest.push_back(i);
        std::cout << "first vector list: ";
        test.display_vec();
        std::cout << std::endl << "second vector list: ";
        display_vec(vectest);
        std::cout << std::endl;
        test.addRange(vectest.begin(), vectest.end());
        std::cout << std::endl << "after join: ";
        test.display_vec();
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Should display error max numbers ===" << std::endl;
    try
    {
        Span test(5);
        int tab[] = {34, 54, 65, 12, 78};
        for(int i = 0;i < 5;i++)
            test.addNumber(tab[i]);
        test.addNumber(87);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Should display min and max random gen ===" << std::endl;
    try
    {
        Span test(10000);
        std::vector<int> vectest;
        for(int i = 0;i < 10000;i++)
            vectest.push_back(rand());
        test.addRange(vectest.begin(), vectest.end());
        std::cout << "min: " << test.shortestSpan() << std::endl << "max: " << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Should display error cause there is only one number in vector ===" << std::endl;
    try
    {
        Span test(10);
        test.addNumber(1);
        std::cout << "min: " << test.shortestSpan() << std::endl << "max: " << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Should display error cause vector is empty ===" << std::endl;
    try
    {
        Span test(10);
        std::cout << "min: " << test.shortestSpan() << std::endl << "max: " << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Canonical tests ===" << std::endl;
    Span test(10);
    for(int i = 0;i<6;i++)
        test.addNumber(i);
    Span test2(test);
    test2.addNumber(34);
    Span test3;
    test3 = test;
    test3.addNumber(67);
    test.display_vec();
    std::cout << std::endl;
    test2.display_vec();
    std::cout << std::endl;
    test3.display_vec();
    std::cout << std::endl;
}

