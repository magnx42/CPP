#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer(Serializer& other)
{
    (void)other;
    std::cout << "Default Serializer copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(Serializer& other)
{
    (void)other;
    return std::cout << "Default Serializer assignation operator= called" << std::endl, *this;
}

Serializer::~Serializer()
{
    std::cout << "Default Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

