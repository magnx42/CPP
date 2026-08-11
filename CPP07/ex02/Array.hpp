#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template <typename T>
class Array{
private:
    unsigned int size;
    T *t;
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    unsigned int size() const;
    class OutOfBoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    operator[](unsigned int size) const;
};



#endif