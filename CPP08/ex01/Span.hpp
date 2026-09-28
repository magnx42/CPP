#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <exception>
class Span{
private:
    unsigned int n;
    std::vector<int> v;
public:
    Span();
    Span(unsigned int capacity);
    Span(const Span &other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int number);
    unsigned int longestSpan() const;
    unsigned int shortestSpan() const;
    void addRange(std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2);
    void display_vec() const;
    class EmptyOrOne : public std::exception
    {
    public:
        const char * what() const throw();
    };
    class MaxElements : public std::exception
    {
    public:
        const char * what() const throw();
    };
};

#endif