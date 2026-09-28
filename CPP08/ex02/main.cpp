#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>

// Affiche un intervalle [first, last) sur une seule ligne.
// La fonction est template sur le type d'itérateur : la même sert pour MutantStack
// et pour std::list. C'est exactement ce que rend possible le fait d'avoir exposé
// begin() et end() — un algorithme ne connaît qu'une paire d'itérateurs.
template <typename Iterator>
static void printRange(Iterator first, Iterator last)
{
    for (Iterator it = first; it != last; ++it)
    {
        if (it != first)
            std::cout << " | ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== Main du sujet, avec MutantStack ===" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        // Ne teste rien à l'exécution : c'est un test de compilation.
        // Cette ligne ne compile pas si l'héritage n'est pas public.
        std::stack<int> s(mstack);
    }

    std::cout << std::endl << "=== Le même scénario avec std::list ===" << std::endl;
    std::cout << "=== Les deux blocs doivent être identiques ===" << std::endl;
    {
        std::list<int> lst;

        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;

        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << std::endl << "=== Forme canonique ===" << std::endl;
    {
        MutantStack<int> original;
        for (int i = 1; i <= 3; ++i)
            original.push(i);

        MutantStack<int> copy(original);
        copy.push(99);

        MutantStack<int> assigned;
        assigned = original;
        assigned.push(42);

        // Les trois piles doivent être indépendantes : original ne bouge pas.
        std::cout << "original : ";
        printRange(original.begin(), original.end());
        std::cout << "copie    : ";
        printRange(copy.begin(), copy.end());
        std::cout << "affectee : ";
        printRange(assigned.begin(), assigned.end());
    }

    std::cout << std::endl << "=== La pile est devenue compatible avec <algorithm> ===" << std::endl;
    {
        MutantStack<int> ms;
        ms.push(42);
        ms.push(7);
        ms.push(19);
        ms.push(7);
        ms.push(3);

        // begin() pointe le FOND de la pile : on parcourt dans l'ordre des insertions,
        // pas dans l'ordre de dépilement. C'est la sémantique du conteneur sous-jacent,
        // pas celle de la pile.
        std::cout << "parcours (fond -> sommet) : ";
        printRange(ms.begin(), ms.end());
        std::cout << "top()                     : " << ms.top() << std::endl;

        // Aucun de ces algorithmes n'a été écrit pour une pile.
        std::cout << "max_element               : " << *std::max_element(ms.begin(), ms.end()) << std::endl;
        std::cout << "min_element               : " << *std::min_element(ms.begin(), ms.end()) << std::endl;
        std::cout << "count(7)                  : " << std::count(ms.begin(), ms.end(), 7) << std::endl;

        // std::find ne lève jamais : l'échec est une valeur de retour, end().
        MutantStack<int>::iterator found = std::find(ms.begin(), ms.end(), 19);
        std::cout << "find(19)                  : " << (found != ms.end() ? "trouve" : "absent") << std::endl;
        MutantStack<int>::iterator missing = std::find(ms.begin(), ms.end(), 404);
        std::cout << "find(404)                 : " << (missing != ms.end() ? "trouve" : "absent") << std::endl;
    }

    std::cout << std::endl << "=== Pile vide ===" << std::endl;
    {
        MutantStack<int> empty;

        std::cout << "size()           : " << empty.size() << std::endl;
        std::cout << "begin() == end() : " << (empty.begin() == empty.end() ? "oui" : "non") << std::endl;
        std::cout << "parcours         : ";
        printRange(empty.begin(), empty.end());
    }

    return 0;
}
