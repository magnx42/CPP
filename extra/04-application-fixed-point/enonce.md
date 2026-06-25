# Module 04 — Application au point fixe (`Fixed`)

## Objectif

Relier tout ce que tu viens d'apprendre (`<<`, `>>`) au vrai problème : pourquoi la
classe `Fixed` stocke ses valeurs décalées, et comment les conversions marchent.
Pas de code de la classe ici — uniquement le raisonnement.

## Rappel minimal

Un `int` ne sait stocker que des entiers : `42`, pas `42.42`. Pourtant `Fixed` doit
représenter des valeurs avec une partie fractionnaire, **en n'utilisant qu'un `int`**.

L'astuce du « point fixe » : on réserve un certain nombre de bits (ici `_bits = 8`,
soit les 8 bits de poids faible) pour la partie fractionnaire. Concrètement, au lieu
de stocker la valeur réelle, on stocke :

```
_value = valeur_réelle × 2^_bits     (= valeur_réelle × 256)
```

Les `<<` et `>>` servent à entrer et sortir de cette représentation.

## Exercices — à faire sur papier d'abord (raisonnement, pas de code)

**Ex 1 — l'aller (construction depuis un int).**
Le constructeur `Fixed(const int n)` doit stocker `n` au format point fixe.
- Pour `n = 42`, quelle valeur faut-il mettre dans `_value` ?
- Exprime cette opération avec un décalage : `_value = n << ?`
- Pourquoi un décalage à **gauche** ici, et pas à droite ?

**Ex 2 — l'aller (construction depuis un float).**
Pour `Fixed(const float n)` avec `n = 42.42` :
- On ne peut pas faire `<<` sur un float. On fait une multiplication : par combien ?
- Calcule `42.42 × 256` à la main (ordre de grandeur suffit).
- Le résultat n'est pas entier (`10859.52`). On doit le ranger dans un `int`.
  Si on coupe tout simplement (troncature), on perd quoi ? Pourquoi arrondir
  (`10860`) serait plus juste que tronquer (`10859`) ?

**Ex 3 — le retour (`toFloat`).**
On a `_value = 10860`. `toFloat()` fait `(float)_value / 256`.
- Calcule `10860 / 256` en gardant les décimales.
- Compare à la valeur de départ `42.42`. C'est exactement pareil ? S'il y a un écart,
  d'où vient-il ?

**Ex 4 — le retour (`toInt`).**
`toInt()` fait `_value >> 8`.
- Que donne `10860 >> 8` ? (utilise ta règle du module 03)
- Pourquoi ça revient à « jeter la partie fractionnaire » et garder l'entier ?

**Ex 5 — la synthèse.**
Explique avec tes mots, en une ou deux phrases : pourquoi `Fixed` a besoin de `<<`
à la construction ET de `>>` (ou de la division) à la lecture. Qu'est-ce que ces deux
opérations sont l'une par rapport à l'autre ?

**Ex 6 — pourquoi 8 bits ?**
Avec `_bits = 8`, la plus petite valeur fractionnaire représentable est `1/256`.
- Si on avait pris `_bits = 4` au lieu de `8`, est-ce qu'on serait plus ou moins
  précis ? Pourquoi ?
- Quel serait le compromis (qu'est-ce qu'on perdrait en augmentant `_bits` ?)

## Zone réponses

- Ex 1 :
- Ex 2 :
- Ex 3 :
- Ex 4 :
- Ex 5 :
- Ex 6 :

## C'est bon ?

Si tu réponds correctement aux Ex 3, 4 et 5, tu as compris le point fixe ET le bit
shifting. À ce stade, relire ton `Fixed.cpp` devrait te paraître évident — et tu
verras tout de suite pourquoi le `static_cast<float>(_value)` tout seul ne suffisait pas.
