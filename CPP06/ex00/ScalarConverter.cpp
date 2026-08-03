#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>

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

static double todouble(std::string str)
{
    double nb = 0;
    if(!str.empty())
    {
        std::string s = str;
        std::stringstream ss(s);
        ss >> nb;
        if(ss.fail())
        {
            std::cout << "double : Impossible to convert" << std::endl;
            exit(1);
        }
    }
    return nb;
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

static std::string gettype(std::string str)
{
    if(str.length() == 1 && isascii(static_cast<int>(str[0])))
        return "CHAR";
    else if(find_occurence(str, '.') == 1 && str.find_first_not_of("0987654321.") == std::string::npos)
        return "DOUBLE";
    else if (find_occurence(str, '.') == 1 && find_occurence(str, 'f') == 1 && str.find_first_not_of("0987654321.f") == std::string::npos)
        return "FLOAT";
    else if (str.find_first_not_of("1234567890") == std::string::npos)
        return "INT";
    else if(str == "-inff" || str == "+inff" || str == "nanf")
        return "PSEUDO";
    else
        return "INVALID";
    
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
    {
        newstr = literal;
    }
    std::string type = gettype(literal);
    double nb = todouble(newstr);
    if(nb < 0 ||  nb > 127)
        std::cout << "char : Impossible" << std::endl;
    else if (!isprint(static_cast<char>(nb)))
        std::cout << "char : Non displayable" << std::endl;
    else    
        std::cout << "char : " << static_cast<char>(nb) << std::endl;
    std::cout << "int : " << static_cast<int>(nb) << std::endl;
    std::cout << "float : " << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double : " << nb << std::endl;
}