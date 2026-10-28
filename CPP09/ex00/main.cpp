#include "BitcoinExchange.hpp"







int main(int ac, char **av)
{
    if(ac != 2)
        return std::cerr << "Error: could not open file." << std::endl, 1;
    std::ifstream inp_file(av[1]);
    std::ifstream data_file("data.csv");
    if(!inp_file)
        return std::cerr << "Error: can't open " << av[1] << " file", 1;
    if(!data_file)
        return std::cerr << "Error: can't open data.csv file" << std::endl, 1;

    // ===============================
    // fonctionne
    // ===============================
    try
    {
        BitcoinExchange caca;
        caca.loadData(data_file);
        caca.printValue(inp_file);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    // ===============================
    // ne fonctionne pas
    // ===============================
    // try
    // {
    //     std::ifstream input_file_bad("BitcoinExchange.cpp");
    //     BitcoinExchange caca;
    //     caca.loadData(data_file);
    //     caca.printValue(input_file_bad);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
}