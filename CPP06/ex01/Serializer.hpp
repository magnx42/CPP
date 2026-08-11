#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include <iostream>

struct Data {
    std::string name;
    std::string type;
    int lifePoint;
};

class Serializer {
private:
    Serializer();
public:
    Serializer& operator=(Serializer& other);
    Serializer(Serializer& other);
    ~Serializer();
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif