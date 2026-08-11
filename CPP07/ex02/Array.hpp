#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>

template <typename T>
class Array{
private:
    unsigned int _tabSize;
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

template <typename T>
Array<T>::Array() : _tabSize(0), t(new T[0])
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _tabSize(n), t(new T[n]())
{
}

template <typename T>
Array<T>::Array(const Array& other)
{
	this->t = new T[other._tabSize];
	this->_tabSize = other._tabSize;
	for(unsigned int i = 0;i < _tabSize;i++)
		this->t[i] = other.t[i];
}

#endif