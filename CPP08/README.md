# CPP Module 08 — Templated containers, iterators, algorithms

Trois exercices (`easyfind`, `Span`, `MutantStack`) mais **un seul vrai sujet** :
comprendre que la STL sépare le *rangement* des données (le conteneur) du
*parcours* des données (l'itérateur), et que c'est cette séparation qui permet
d'écrire un algorithme une fois pour toutes.

Si tu ne retiens qu'une phrase de ce module : **un algorithme STL ne connaît
jamais le conteneur sur lequel il travaille, il ne connaît qu'une paire
d'itérateurs.**

---

## 0. Règles 42 à respecter (toujours)

- Compilation : `c++ -Wall -Wextra -Werror -std=c++98`. Zéro warning toléré.
- Include guards (`#ifndef / #define / #endif`) sur chaque header.
- **Exception au module** : le code d'un template *doit* être dans le header
  (`.hpp` ou `.tpp` inclus à la fin du `.hpp`). Le compilateur a besoin de voir
  le corps pour l'instancier. C'est la seule situation où on écrit une
  implémentation dans un header.
- Orthodox Canonical Form obligatoire sur toute **classe** (donc sur `Span` et
  `MutantStack`, pas sur `easyfind` qui est une simple fonction).
- Chaque header doit être utilisable seul → il inclut ce dont il se sert.

---

## 1. C'est quoi un conteneur ?

En C, gérer une collection demandait trois choses séparées, à la main :

```c
int   *tab  = (int *)malloc(sizeof(int) * 10);  // la mémoire
size_t size = 0;                                 // combien d'éléments utilisés
size_t cap  = 10;                                // combien on peut en mettre
// ... et free(tab) à la fin, sans jamais l'oublier
```

Un **conteneur** C++, c'est exactement ces trois choses, mais emballées dans une
classe qui s'occupe de tout :

```cpp
#include <vector>

std::vector<int> v;   // pas de malloc, pas de taille à suivre
v.push_back(42);      // il s'agrandit tout seul si besoin
std::cout << v.size() << std::endl;
// pas de free : le destructeur de v libère tout à la sortie du scope
```

Deux propriétés à avoir en tête :

1. **Le conteneur possède ses éléments.** Quand il meurt, ils meurent. Tu ne
   libères jamais rien à la main.
2. **Il est typé.** `std::vector<int>` ne contient que des `int` — le compilateur
   le vérifie. Le `<int>` entre chevrons, c'est un argument de template : tu as
   vu la mécanique en CPP07, la STL n'est que du template appliqué à grande
   échelle.

---

## 2. Les trois conteneurs séquentiels

Ils stockent tous une suite d'éléments dans l'ordre où tu les mets. Ils diffèrent
uniquement par **la façon dont ils rangent ça en mémoire** — et tout le reste
découle de là.

### `std::vector<int>` — un bloc contigu

```
adresses :  0x100  0x104  0x108  0x10c  0x110
           +------+------+------+------+------+
           |  1   |  2   |  3   |  4   |  5   |
           +------+------+------+------+------+
           ^                                   ^
        begin()                              end()
```

Les éléments se touchent. Pour aller au 4ᵉ, on calcule `adresse_de_base + 3` :
instantané. Mais insérer au milieu oblige à décaler tout ce qui suit.

### `std::list<int>` — des maillons chaînés

```
   +-------+       +-------+       +-------+
   |   1   | <---> |   2   | <---> |   3   |
   +-------+       +-------+       +-------+
    0x8a20          0x4f10          0xc330      <- adresses sans aucun rapport
```

Chaque maillon connaît son voisin de gauche et de droite. Pour aller au 4ᵉ, il
faut faire 3 sauts : lent. Mais insérer au milieu, c'est débrancher deux flèches
et en rebrancher quatre : gratuit, quelle que soit la taille de la liste.

### Tableau de décision

| | `std::vector` | `std::deque` | `std::list` |
|---|---|---|---|
| Mémoire | un bloc contigu | blocs chaînés | maillons individuels |
| `c[i]` (accès indexé) | O(1) — oui | O(1) — oui | **impossible** |
| Ajout en fin | O(1) amorti | O(1) | O(1) |
| Ajout en tête | O(n) — décale tout | O(1) | O(1) |
| Insertion au milieu | O(n) | O(n) | O(1) si tu y es déjà |
| À utiliser | par défaut, 90 % des cas | ajouts aux deux bouts | beaucoup d'insertions/suppressions |

**En pratique : prends `std::vector` sauf raison précise de faire autrement.**
La contiguïté mémoire le rend souvent plus rapide que la théorie ne le laisse
croire (le cache CPU adore les données qui se touchent).

---

## 3. Les itérateurs — le cœur du module

Un `vector` se parcourt par index, une `list` non. Il fallait donc une manière
uniforme de dire « l'élément courant » pour n'importe quel conteneur : c'est
l'**itérateur**. Il s'utilise exactement comme un pointeur.

```cpp
std::vector<int>::iterator it = v.begin();
std::cout << *it << std::endl;   // déréférencement : la valeur pointée
++it;                            // avancer d'un cran
```

### `begin()` et `end()`

```cpp
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
```

`begin()` pointe sur le **premier élément**. `end()` pointe **juste après le
dernier** — ce n'est pas un élément, c'est une borne.

> **Piège classique.** `end()` est un itérateur valide, mais **non
> déréférençable**. Faire `*it` quand `it == end()` est un comportement
> indéfini : ça ne crashe pas forcément, ça lit de la mémoire au hasard. C'est
> précisément pour ça que `easyfind` doit lever une exception plutôt que de
> laisser l'appelant se débrouiller avec un `end()` qu'il oublierait de tester.

Noter aussi le `it != v.end()` dans la boucle, et pas `it < v.end()` : la
comparaison `<` n'existe pas sur les itérateurs de `list` (voir ci-dessous).

### Un itérateur n'est pas un index

Sur `{1 2 3 4 5}`, chercher `4` renvoie un itérateur qui *pointe* sur le `4`, pas
le nombre `3`. Si tu veux vraiment la position numérique :

```cpp
#include <iterator>
std::cout << std::distance(v.begin(), it) << std::endl;   // affiche 3
```

`std::distance` compte les crans entre deux itérateurs. Sur un `vector` c'est une
soustraction ; sur une `list` il parcourt réellement les maillons.

### `iterator` vs `const_iterator`

```cpp
std::vector<int>::iterator       it;   // *it est modifiable
std::vector<int>::const_iterator cit;  // *cit est en lecture seule
```

Sur un conteneur `const`, `begin()` renvoie un `const_iterator`, jamais un
`iterator`. C'est pour ça qu'on écrit souvent **deux surcharges** de `easyfind` :
une pour `T&` renvoyant `T::iterator`, une pour `const T&` renvoyant
`T::const_iterator`. Sans la seconde, appeler `easyfind` sur un conteneur
constant ne compile pas.

### Catégories d'itérateurs

Tous les itérateurs ne savent pas faire les mêmes choses :

| Conteneur | Catégorie | `++it` | `--it` | `it + 3` | `it1 < it2` |
|---|---|---|---|---|---|
| `vector`, `deque` | random access | ✅ | ✅ | ✅ | ✅ |
| `list`, `set`, `map` | bidirectional | ✅ | ✅ | ❌ | ❌ |

Une `list` ne peut pas sauter de 3 crans d'un coup : ses maillons sont éparpillés,
il **faut** passer par les intermédiaires. D'où `std::advance(it, 3)` quand tu
veux avancer de façon générique.

### `typename` : le piège de compilation n°1

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int n);
//  ^^^^^^^^ obligatoire
```

Quand le compilateur lit le template, `T` est encore inconnu — il ne peut pas
savoir si `T::iterator` désigne un **type** ou un **membre statique**. Par défaut,
il suppose que ce n'est *pas* un type, et tu récupères une erreur cryptique du
genre `expected ';' before easyfind`. Le mot-clé `typename` lui dit
explicitement : « fais-moi confiance, c'est un type ».

**Règle simple : dès que tu écris `T::quelquechose` comme un type dans un
template, mets `typename` devant.**

---

## 4. Les algorithmes — `<algorithm>`

C'est ici que la séparation prend tout son sens. `std::find` ne prend **pas** un
conteneur, il prend deux itérateurs et une valeur :

```cpp
#include <algorithm>

std::vector<int>::iterator it = std::find(v.begin(), v.end(), 4);
```

Comme il ne connaît que des itérateurs, la *même* fonction marche sur `vector`,
`list`, `deque`, sur un sous-intervalle, ou même sur un tableau C via des
pointeurs. Elle a été écrite une fois.

### La convention de la sentinelle

`std::find` **ne lève jamais d'exception**. Quand il ne trouve pas, il renvoie
l'itérateur de fin qu'on lui a donné :

```cpp
if (it == v.end())
    std::cout << "pas trouvé" << std::endl;
```

C'est une convention omniprésente dans la STL : l'échec est une *valeur de
retour*, pas une erreur. `end()` joue le rôle de « rien ». Et c'est exactement ce
qui te reste à faire dans `easyfind` : transformer cette sentinelle silencieuse
en exception bruyante, pour que l'appelant ne puisse pas l'ignorer par
distraction.

---

## 5. ex00 — `easyfind`

> *"Assuming T is a container of integers, this function must find the first
> occurrence of the second parameter in the first parameter."*

`T` n'est donc **pas un tableau C** : c'est le type d'un conteneur STL d'`int`.
Le template n'exige rien de plus que « sait exposer `begin()` et `end()` ».

### Signatures attendues

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int n);

template <typename T>
typename T::const_iterator easyfind(const T& container, int n);   // pour les const
```

Un **seul** paramètre template (`T`), pas deux : `n` est un `int` tout court.

### Les trois étapes du corps

1. appeler `std::find(container.begin(), container.end(), n)`
2. comparer le résultat à `container.end()`
3. si égal → `throw` ton exception ; sinon → renvoyer l'itérateur

### La classe d'exception

```cpp
class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "easyfind: value not found in container";
        }
};
```

Quatre détails, tous vérifiés à la compilation (g++ 14.2 / clang 19.1,
`-Wall -Wextra -Werror -std=c++98`) :

- **`throw()` en fin de signature** — obligatoire. En C++98, une méthode qui en
  redéfinit une autre ne peut pas être *plus permissive* que la base sur les
  exceptions ; or `std::exception::what()` est déclarée `throw()`. L'omettre
  donne `looser exception specification on overriding virtual function` chez
  g++, `exception specification of overriding function is more lax than base
  version` chez clang. Les deux refusent.
- **`const char*` et non `char*`** — et c'est le piège le plus vicieux du module,
  parce que **les deux compilateurs ne sont pas d'accord** : g++ sort
  `invalid covariant return type`, un *warning* que `-Werror` transforme en
  erreur ; clang, lui, **accepte silencieusement**, même avec `-Wall -Wextra`.
  Traduction : si tu développes sous clang, ton code compile chez toi et casse
  chez le correcteur.
- **`public:` explicite** — nuance importante : ce n'est pas *toujours* requis
  pour compiler. Le contrôle d'accès porte sur le type par lequel tu appelles.
  Si le `main` attrape par `catch (const std::exception& e)`, `e.what()` passe
  par la base où la méthode est publique → **ça compile même si ton `what()` est
  private**. Mais dès qu'on attrape par `catch (const E& e)` ou qu'on appelle sur
  l'objet dérivé, c'est `is private within this context`. Autrement dit un
  `what()` private est une bombe à retardement que ton propre test ne déclenche
  pas. Mets `public:`.
- **un `;` après l'accolade fermante de la classe** — sinon l'erreur tombe
  plusieurs lignes plus bas, loin de la faute.

### Le `main` de test

Il doit montrer que le template est réellement générique — donc **au moins deux
conteneurs différents** — et couvrir le cas d'échec :

```cpp
std::vector<int> v;
v.push_back(1); v.push_back(2); v.push_back(3);

std::list<int> l;
l.push_back(10); l.push_back(20);

try {
    std::vector<int>::iterator it = easyfind(v, 2);
    std::cout << "trouvé : " << *it << std::endl;
    easyfind(l, 99);   // doit lever
}
catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

---

## 6. Pièges C++98

Tout le code STL moderne que tu trouveras en ligne est du C++11+. Ces trois
formes **ne compilent pas** avec `-std=c++98` :

| ❌ C++11 | ✅ C++98 |
|---|---|
| `std::vector<int> v = {1, 2, 3};` | `v.push_back(1); v.push_back(2); ...` |
| `for (int x : v)` | `for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)` |
| `auto it = v.begin();` | `std::vector<int>::iterator it = v.begin();` |
| `v.emplace_back(1);` | `v.push_back(1);` |
| `nullptr` | `NULL` ou `0` |

Autre piège de syntaxe : dans un template imbriqué, écris
`std::vector<std::vector<int> >` avec **une espace** entre les deux `>`. En
C++98, `>>` est lu comme l'opérateur de décalage.

---

## 7. Checklist avant soutenance

- [ ] `c++ -Wall -Wextra -Werror -std=c++98` → zéro warning
- [ ] Le template est testé sur **au moins deux conteneurs différents**
      (`vector` + `list`) — c'est la question que le correcteur pose en premier
- [ ] Le cas « valeur absente » est testé et l'exception est bien attrapée
- [ ] Le cas conteneur **vide** est testé
- [ ] `valgrind --leak-check=full ./easyfind` → 0 leak, 0 error
- [ ] Aucun `auto`, aucun range-for, aucune init-list dans le rendu
- [ ] Le corps du template est dans le header (pas dans un `.cpp`)
- [ ] Tu sais expliquer à l'oral : pourquoi `typename`, pourquoi `end()` ne se
      déréférence pas, et pourquoi `std::find` marche sur `list` comme sur
      `vector`
