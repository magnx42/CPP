#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T, typename F>
void iter(T *tab, const int len, F f)
{
    for(int i = 0;i < len;i++)
        f(tab[i]);
}

template <typename T>
void display(T t)
{
    std::cout << t;
}

template <typename T>
void moreone(T &t)
{
    t++;
}

#endif