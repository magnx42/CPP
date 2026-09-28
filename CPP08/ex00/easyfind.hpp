#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <algorithm>
class NoIndex : public std::exception {
public:
    const char * what() const throw()
    {
        return "No index find";
    }
};

template <typename T>
typename T::const_iterator easyfind(const T &conteneur, int n)
{
    typename T::const_iterator it = std::find(conteneur.begin(), conteneur.end(), n);
    if(it == conteneur.end())
        throw NoIndex();
    return it;
}

#endif