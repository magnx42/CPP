#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>
#include <limits.h>
#include <cfloat>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
    std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
    (void)other;
    std::cout << "Default ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
    (void)other;
    std::cout << "Default assignation ScalarConverter called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default ScalarConverter destructor called" << std::endl;
}

static int find_occurence(std::string str, char c)
{
    int nb = 0;
    for(int i = 0;str[i];i++)
    {
        if(str[i] == c)
            nb++;
    }
    return nb;
}

static e_type gettype(std::string str)
{
    if(str.empty())
        return INVALID;
    else if(str.length() == 1 && isascii(static_cast<int>(str[0])) && !isdigit(str[0]))
        return CHAR;
    else if(find_occurence(str, '.') == 1 && str.find_first_not_of("+-0987654321.") == std::string::npos)
        return DOUBLE;
    else if (find_occurence(str, '.') == 1 && find_occurence(str, 'f') == 1 && str.find_first_not_of("+-0987654321.f") == std::string::npos)
        return FLOAT;
    else if (str.find_first_not_of("+-1234567890") == std::string::npos)
        return INT;
    else if(str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
        return PSEUDO;
    else
        return INVALID;
    
}

void DisplayPseudo(const std::string str)
{
    if(str == "+inff" || str == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if(str == "-inff" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if(str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void DisplayChar(std::string str)
{
    char c = 0;
    if(str.length() == 1)
        c = str[0];
    std::cout << "char: ";
    if(isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void DisplayInt(std::string str)
{
    long int nb;
    char *end;
    nb = std::strtol(str.c_str(), &end, 10);
    if(*end != '\0' || end == str.c_str())
        return (void)(std::cout << "Parsing error : int" << std::endl);
    if(nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if(isprint(static_cast<char>(nb)))
            std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    if(nb <= INT_MAX && nb >= INT_MIN)
        std::cout << "int: " << nb << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if(nb > -FLT_MAX && nb < FLT_MAX)
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    if(static_cast<double>(nb) > -DBL_MAX && static_cast<double>(nb) < DBL_MAX)
        std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

void DisplayFloat(std::string str)
{
    double nb;
    char *end;

    nb = std::strtod(str.c_str(), &end);
    if(end == str.c_str() || (*end != '\0' && !(end[0] == 'f' && end[1] == '\0')))
        return (void)(std::cout << "Parsing error: float" << std::endl);
    if(nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if(isprint(static_cast<char>(nb)))
            std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    if(static_cast<long int>(nb) <= INT_MAX && static_cast<long int>(nb) >= INT_MIN)
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if(static_cast<float>(nb) > -FLT_MAX && static_cast<float>(nb) < FLT_MAX)
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    if(nb > -DBL_MAX && nb < DBL_MAX)
        std::cout << "double: " << nb << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void DisplayDouble(std::string str)
{
    double nb;
    char *end;
    nb = std::strtod(str.c_str(), &end);
    if(*end != '\0' || end == str.c_str())
        return (void)(std::cout << "Parsing error: double" << std::endl);
    if(nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if(isprint(static_cast<char>(nb)))
            std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    if(static_cast<long int>(nb) <= INT_MAX && static_cast<long int>(nb) >= INT_MIN)
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if(static_cast<float>(nb) > -FLT_MAX && static_cast<float>(nb) < FLT_MAX)
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    if(nb > -DBL_MAX && nb < DBL_MAX)
        std::cout << "double: " << nb << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void DisplayInvalid()
{
    std::cout << "Error: invalid input" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
    std::string newstr;
    if(!literal.empty() && ((literal[0] == '\'' && literal[literal.length() - 1] == '\'') || (literal[0] == '\"' && literal[literal.length() - 1] == '\"')))
    {
        for (size_t i = 1;i < literal.length() - 1;i++)
            newstr.push_back(literal[i]);
    }
    else
        newstr = literal;
    e_type type = gettype(newstr);
    //permet de faire en sorte que les sorties terminal soient ecrites en entieres et aps en ecritures scientifiques.
    std::cout << std::fixed << std::setprecision(1);
    if(type == PSEUDO)
        DisplayPseudo(newstr);
    else if (type == CHAR)
        DisplayChar(newstr);
    else if (type == INT)
        DisplayInt(newstr);
    else if (type == FLOAT)
        DisplayFloat(newstr);
    else if (type == DOUBLE)
        DisplayDouble(newstr);
    else if (type == INVALID)
        DisplayInvalid();
}