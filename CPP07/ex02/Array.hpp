#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <iostream>

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
        virtual const char* what() const throw()
		{
			return "Out of bound";
		}
    };
    const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
};

template <typename T>
Array<T>::Array() : _tabSize(0), t(new T[0])
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _tabSize(n), t(new T[n]()	)
{
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if(this != &other)
	{
		this->_tabSize = other._tabSize;
		if(this->t)
			delete[] this->t;
		this->t = new T[_tabSize];
		for(unsigned int i = 0;i < _tabSize;i++)
			this->t[i] = other.t[i];
	}
	return *this;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	this->t = new T[other._tabSize];
	this->_tabSize = other._tabSize;
	for(unsigned int i = 0;i < _tabSize;i++)
		this->t[i] = other.t[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _tabSize;
}

template <typename T>
Array<T>::~Array()
{
	delete[] t;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if(index >= _tabSize)
		throw OutOfBoundException();
	return t[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if(index >= _tabSize)
		throw OutOfBoundException();
	return t[index];
}

#endif