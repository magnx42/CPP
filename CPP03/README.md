# CPP Module 03 — Inheritance (Héritage)

Famille de classes : `ClapTrap → ScavTrap / FragTrap → DiamondTrap`.
Objectif du module : comprendre l'héritage en C++98, du plus simple (une classe
mère, une fille) au plus piégeux (héritage multiple en diamant).

---

## 0. Règles 42 à respecter (toujours)

- Compilation : `c++ -Wall -Wextra -Werror -std=c++98`. Zéro warning toléré.
- **Orthodox Canonical Form (OCF)** obligatoire sur chaque classe.
- Include guards (`#ifndef / #define / #endif`) sur chaque header.
- Aucune implémentation de fonction dans un `.hpp` (hors templates).
- Chaque message finit par un newline (`std::endl`).
- Chaque header doit être utilisable seul → inclure ce qu'il utilise
  (ex. `#include <string>` si on se sert de `std::string`).

---

## 1. L'héritage : le concept de base

Une classe **dérivée** (fille) hérite des attributs et méthodes d'une classe
**base** (mère).

```cpp
class ScavTrap : public ClapTrap { ... };
```

- `ScavTrap` est un ClapTrap (« is-a »). Il récupère `attack`, `takeDamage`,
  `beRepaired`, et les attributs de ClapTrap.
- Il peut **ajouter** ses propres méthodes (`guardGate`) et **redéfinir**
  celles de la mère (`attack` avec un autre message).

### Public / protected / private en héritage
- `public` : héritage « is-a » normal. **C'est ce qu'on veut ici.**
- Sans mot-clé devant une base d'une `class`, l'héritage est **private** par
  défaut → piège classique. `class D : public A, B` rend B **privé**. Il faut
  répéter `public` : `class D : public A, public B`.

### private vs protected dans la mère
- `private` : invisible même pour les filles.
- `protected` : visible par les filles, pas par l'extérieur.
- → On a passé les attributs de ClapTrap de `private` à **`protected`** dès
  ex01 pour que ScavTrap/FragTrap puissent y accéder.

---

## 2. Orthodox Canonical Form (OCF)

Les 4 fonctions que toute classe doit fournir (« rule of three » + défaut) :

| # | Fonction | Signature |
|---|----------|-----------|
| 1 | Constructeur par défaut | `ClassName();` |
| 2 | Constructeur par copie | `ClassName(const ClassName& other);` |
| 3 | Opérateur d'affectation | `ClassName& operator=(const ClassName& other);` |
| 4 | Destructeur | `~ClassName();` |

Pourquoi ? Si on n'écrit rien, le compilateur génère une copie superficielle
(membre par membre). Dès qu'on gère une ressource, ça casse. L'OCF force à
prendre le contrôle des 3 moments de copie/destruction.

**Point clé `operator=`** : il doit retourner `*this` par **référence**
(`ClassName&`), pas une copie, pour permettre le chaînage `a = b = c`. Et
protéger l'auto-affectation avec `if (this != &other)`.

Le constructeur prenant un nom (`ClapTrap(std::string name)`) **n'est pas** une
des 4 : c'est un constructeur paramétré en plus, légitime.

---

## 3. Chaînage construction / destruction

Quand on construit une fille, la mère est construite **d'abord**, la fille
**ensuite**. La destruction se fait dans l'**ordre inverse**.

```
Création ScavTrap : ClapTrap ctor → ScavTrap ctor
Destruction       : ScavTrap dtor → ClapTrap dtor
```

Pourquoi cet ordre ? La fille peut utiliser la partie mère ; il faut donc que
la mère existe avant la fille, et qu'elle soit détruite après (la fille pourrait
encore s'en servir dans son destructeur).

### Passer un argument au constructeur de la mère
Via la **liste d'initialisation** :

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { ... }
```

Sans ça, c'est le constructeur **par défaut** de ClapTrap qui est appelé, et on
devrait réaffecter le nom à la main (moins propre).

---

## 4. Le problème du diamant (ex03) — LE point central

DiamondTrap hérite de ScavTrap **et** FragTrap, qui héritent tous deux de
ClapTrap :

```
        ClapTrap
        /      \
   ScavTrap   FragTrap
        \      /
       DiamondTrap
```

**Sans précaution**, DiamondTrap contient **deux** ClapTrap (un par branche).
Conséquences :
- Tout membre de ClapTrap (`_name`, `_lifePoint`...) devient **ambigu** :
  le compilateur ne sait pas lequel des deux tu vises → erreur `ambiguous`.
- ClapTrap est construit deux fois → viole la consigne « once and only once ».

### La solution : l'héritage virtuel
Le `virtual` se met là où la **base commune dupliquée** est héritée, donc
**dans ScavTrap et FragTrap** (pas dans DiamondTrap) :

```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
```

Résultat : un **seul** ClapTrap partagé entre les deux branches. L'ambiguïté
disparaît, plus besoin de `ClapTrap::` partout.

**Piège de l'erreur « toujours ambiguous »** : il faut `virtual` sur les **deux**
(ScavTrap ET FragTrap). Si un seul l'a, il reste deux ClapTrap.

### Construction du diamant
Avec l'héritage virtuel, c'est la classe **la plus dérivée** (DiamondTrap) qui
construit la base virtuelle ClapTrap **directement**. Les appels à ClapTrap dans
les constructeurs de ScavTrap/FragTrap sont **ignorés**.

```cpp
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) { ... }
```

Ordre de construction : `ClapTrap (base virtuelle) → ScavTrap → FragTrap →
DiamondTrap`.

**Conséquence importante sur les attributs** : ScavTrap et FragTrap réaffectent
HP/EP/AD dans leur corps. Le dernier qui passe (FragTrap) écraserait l'énergie à
100. Or le sujet veut EP = 50 (ScavTrap). Donc **DiamondTrap doit fixer
explicitement** les 3 valeurs voulues dans son propre constructeur :
HP=100 (FragTrap), EP=50 (ScavTrap), AD=30 (FragTrap). On ne se fie jamais à
l'ordre.

---

## 5. Shadowing et résolution de portée (ex03)

DiamondTrap a un attribut privé `_name` **du même nom** que celui de ClapTrap.
Il y a donc **deux** `_name` dans le même objet :
- `ClapTrap::_name` (protected) → vaut `name + "_clap_name"`
- `DiamondTrap::_name` (private) → vaut `name`

C'est le **shadowing** (masquage) : la variable la plus proche masque l'autre.
D'où le tip du sujet sur le flag `-Wshadow`.

### Comment viser l'une ou l'autre
- `_name` (dans le code de DiamondTrap) → celui de **DiamondTrap**.
- `ClapTrap::_name` → opérateur de **résolution de portée** `::` pour viser
  celui de **ClapTrap**.

Le suffixe `_clap_name` doit être **stocké** dans `ClapTrap::_name` au moment de
la construction, **pas** recollé à l'affichage. Sinon `attack()` (qui lit
`ClapTrap::_name`) afficherait le mauvais nom.

```cpp
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) {
    _lifePoint = 100; _energyPoint = 50; _attackDamage = 30; // valeurs imposées
    _name = name;                          // DiamondTrap
    ClapTrap::_name = name + "_clap_name"; // ClapTrap
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name is " << _name
              << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}
```

### Lever l'ambiguïté d'une méthode héritée des deux côtés
`attack()` existe via ScavTrap ET FragTrap → ambigu. Le sujet veut celui de
ScavTrap. On le déclare explicitement dans DiamondTrap :

```cpp
using ScavTrap::attack;
```

---

## 6. Tableau des valeurs par classe

| Classe      | Hit points | Energy points | Attack damage | Capacité spéciale | attack() |
|-------------|-----------:|--------------:|--------------:|-------------------|----------|
| ClapTrap    | 10  | 10  | 0  | —                 | ClapTrap |
| ScavTrap    | 100 | 50  | 20 | `guardGate()`     | ScavTrap (redéfini) |
| FragTrap    | 100 | 100 | 30 | `highFivesGuys()` | hérité de ClapTrap |
| DiamondTrap | 100 (Frag) | 50 (Scav) | 30 (Frag) | `whoAmI()` | ScavTrap (`using`) |

---

## 7. Logique métier ClapTrap (rappel ex00)

- `attack` et `beRepaired` coûtent **1 energy point**.
- Aucune action possible si HP ≤ 0 ou energy ≤ 0 (selon l'action).
- Message attack imposé :
  `ClapTrap <name> attacks <target>, causing <damage> points of damage!`
- Constructeurs ET destructeur affichent un message (pour le peer-eval).

---

## 8. Questions de peer-eval à savoir répondre

1. Pourquoi `protected` plutôt que `private` dans ClapTrap dès ex01 ?
2. Dans quel ordre s'affichent les messages ctor/dtor, et pourquoi l'inverse ?
3. Pourquoi le `virtual` va sur ScavTrap/FragTrap et **pas** sur DiamondTrap ?
4. Pourquoi DiamondTrap doit construire ClapTrap lui-même ?
5. Différence entre `_name` et `ClapTrap::_name` ? Pourquoi deux variables ?
6. Pourquoi ne pas se fier à l'ordre de construction pour fixer EP=50 ?
7. À quoi sert `using ScavTrap::attack;` ?
8. Pourquoi `operator=` retourne `ClassName&` et pas `ClassName` ?

---

## 9. Reproduire de zéro (checklist)

1. ClapTrap (OCF, 4 attributs protected, attack/takeDamage/beRepaired, messages).
2. ScavTrap `: virtual public ClapTrap`, override attack, guardGate, valeurs 100/50/20.
3. FragTrap `: virtual public ClapTrap`, highFivesGuys, valeurs 100/100/30.
4. DiamondTrap `: public ScavTrap, public FragTrap`, `_name` privé shadow,
   constructeur qui fixe les valeurs + les deux `_name`, whoAmI, `using ScavTrap::attack`.
5. main qui teste le chaînage + chaque capacité spéciale.
6. Makefile : tous les `.cpp` dans `SRC`, flags corrects.
