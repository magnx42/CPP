#include "Span.hpp"
#include <climits>
#include <algorithm>
#include <iostream>

Span::Span() : n(0)
{
}

Span::Span(unsigned int capacity) : n(capacity)
{
}

Span::Span(const Span& other)
{
    this->n = other.n;
    this->v = other.v;
}

Span& Span::operator=(const Span &other)
{
    if(this != &other)
    {
        this->n = other.n;
        this->v = other.v;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if(v.size() >= n)
        throw MaxElements();
    v.push_back(number);
}

const char * Span::EmptyOrOne::what() const throw()
{
    return "vector is empty or contain only one number";
}

const char* Span::MaxElements::what() const throw()
{
    return "There is already max elements";
}

unsigned int Span::longestSpan() const 
{
    if(v.empty() || v.size() == 1)
        throw EmptyOrOne();
    // std::min/max_element retourne un iterateur donc je calcule a partir de ce que pointe l'iterateur
    return static_cast<unsigned int>(*std::max_element(v.begin(), v.end())) - static_cast<unsigned int>(*std::min_element(v.begin(), v.end()));
}

unsigned int Span::shortestSpan() const 
{
    if(v.empty() || v.size() == 1)
        throw EmptyOrOne();
    std::vector<int> v_tmp = v;
    std::sort(v_tmp.begin(), v_tmp.end());
    unsigned int result = UINT_MAX, tmp = UINT_MAX;
    int i;
    std::vector<int>::iterator it = v_tmp.begin();
    while(it != v_tmp.end())
    {
        i = *it;
        it++;
        if(it != v_tmp.end())
            tmp = static_cast<unsigned int>(*it) - static_cast<unsigned int>(i);
        if(tmp < result)
            result = tmp;
    }
    return result;
}

void Span::addRange(std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2)
{
	if(static_cast<unsigned int>(v.size()) + std::distance(it1, it2) > n)
		throw MaxElements();
	v.insert(v.end(), it1, it2);
}

void Span::display_vec() const
{
    for(std::vector<int>::const_iterator it = v.begin();it != v.end();)
    {
        std::cout << *it;
        it++;
        if(it != v.end())
            std::cout << " | ";
    }
}