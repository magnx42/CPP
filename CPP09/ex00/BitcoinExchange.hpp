#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>


class BitcoinExchange {
private:
    std::map<std::string, double> _data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    void loadData(std::ifstream& data);
    double getValue(const std::string& date) const;
    void printValue(std::ifstream& inp);
    int verifDate(std::string date);
    class CantConvertFromData : public std::exception {
    public:
        const char *what() const throw();
    };
    class CantConvertFromInput : public std::exception {
    public:
        const char *what() const throw();
    };
};

#endif