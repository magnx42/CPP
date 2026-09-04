#include "Array.hpp"
#include <iostream>
#include <string>

// le parametre est const : c'est ce qui force l'appel de l'operator[] const
static void printArray(const Array<int> &arr, const std::string &name)
{
    std::cout << name << " (size " << arr.size() << ") :";
    for(unsigned int i = 0;i < arr.size();i++)
        std::cout << " " << arr[i];
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "=== construction ===" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    Array<int> numbers(5);
    printArray(numbers, "numbers a la construction");

    for(unsigned int i = 0;i < numbers.size();i++)
        numbers[i] = (i + 1) * 10;
    printArray(numbers, "numbers rempli          ");

    std::cout << std::endl << "=== copie profonde : constructeur ===" << std::endl;
    Array<int> copy(numbers);
    copy[0] = 999;
    numbers[1] = -1;
    printArray(numbers, "numbers");
    printArray(copy, "copy   ");

    std::cout << std::endl << "=== copie profonde : operator= ===" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    assigned[0] = 777;
    numbers[2] = -2;
    printArray(numbers, "numbers ");
    printArray(assigned, "assigned");

    std::cout << std::endl << "=== auto-affectation ===" << std::endl;
    Array<int> *self = &assigned;
    assigned = *self;
    printArray(assigned, "assigned apres a = a");

    std::cout << std::endl << "=== acces en lecture seule ===" << std::endl;
    const Array<int> frozen(numbers);
    std::cout << "frozen[0] = " << frozen[0] << std::endl;

    std::cout << std::endl << "=== index hors bornes ===" << std::endl;
    try
    {
        std::cout << numbers[numbers.size()] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "numbers[5] -> " << e.what() << std::endl;
    }
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "empty[0]   -> " << e.what() << std::endl;
    }
    try
    {
        std::cout << frozen[42] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "frozen[42] -> " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Array<std::string> ===" << std::endl;
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "world";
    std::cout << "words.size() = " << words.size() << std::endl;
    for(unsigned int i = 0;i < words.size();i++)
        std::cout << "[" << words[i] << "]";
    std::cout << std::endl;

    return 0;
}
