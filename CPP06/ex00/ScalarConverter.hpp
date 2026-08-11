#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>

enum e_type {
    PSEUDO,
    INVALID,
    DOUBLE,
    CHAR,
    INT,
    FLOAT
};

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter & operator=(const ScalarConverter & other);
    ~ScalarConverter();
public:
    static void convert(std::string literal);
};

#endif