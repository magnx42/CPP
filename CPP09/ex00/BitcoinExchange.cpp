#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    _data = other._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return *this;
}

const char * BitcoinExchange::CantConvertFromData::what() const throw()
{
    return "Error: can't convert number from data.csv";
}

const char * BitcoinExchange::CantConvertFromInput::what() const throw()
{
    return "Error: can't convert number from input file";
}

void BitcoinExchange::loadData(std::ifstream& data)
{
    std::string line;
    std::getline(data, line); // sauter la premiere ligne
    while(std::getline(data, line))
    {
        size_t index = line.find(',');
        std::string date = line.substr(0, index);
        std::string value = line.substr(index + 1, line.size());
        std::istringstream iss(value);
        double rate;
        iss >> rate;
        if (iss.fail() || !iss.eof())
            throw CantConvertFromData();
        _data.insert(std::make_pair(date, rate));
    }
}

double BitcoinExchange::getValue(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _data.upper_bound(date); // upper_bound = aller directement ou la valeur est la date en l'occurence
    if(it == _data.begin()) // date demandee est avant la premiere date de la base
        return -1;
    else //upper_bound renvoie la date juste au dessus celle que l'on demande ou celle qui aurait ete au dessus si elle avait existe donc --it pour recuperer la bonne ou la precedente et si it == end alors aussi --it pour que on ait la derniere date listee
        --it;
    return it->second;
}

void BitcoinExchange::printValue(std::ifstream& inp)
{
    // =======================================
    // meme chose que pour data.csv mais avec un pipe + affichage
    // ======================================= 
    std::string line;
    std::getline(inp, line); // sauter la premiere ligne
    while(std::getline(inp, line))
    {
        size_t index = line.find('|');
        if(index == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, index - 1);
        if(verifDate(date) == -1)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string value = line.substr(index + 2, line.size());
        std::istringstream iss(value);
        double rate;
        iss >> rate;
        if (iss.fail() || !iss.eof())
        {
            std::cout << "Error: can't convert value from input => " << line << std::endl;
            continue;
        }
        if (rate < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (rate > 1000)
        {
            std::cout << "Error: too large number." << std::endl;
            continue;
        }
        std::cout << date << " => " << rate << " = " << rate * getValue(date) << std::endl;
    }
    // =======================================

}

int BitcoinExchange::verifDate(std::string date)
{

    std::string year = date.substr(0, 4);
    std::istringstream issy(year);
    int y;
    issy >> y;
    if (issy.fail() || !issy.eof())
        return -1;

    std::string month = date.substr(5, 2);
    std::istringstream issm(month);
    int m;
    issm >> m;
    if (issm.fail() || !issm.eof())
        return -1;


    std::string day = date.substr(8, 2);
    std::istringstream issd(day);
    int d;
    issd >> d;
    if (issd.fail() || !issd.eof())
        return -1;

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m < 1 || m > 12)
        return -1;
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        daysInMonth[1] = 29;
    if(d < 1 || d > daysInMonth[m - 1])
        return -1;
    if (y < 2009)
        return -1;
    return 0;
}