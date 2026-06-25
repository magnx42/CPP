# Module 01 — Le binaire, les bases

## Objectif

Comprendre comment un nombre entier est représenté en binaire, et savoir le poids
de chaque bit. Sans ça, le décalage de bits (`<<` et `>>`) n'a aucun sens. Ce module
est le socle de tous les suivants.

## Rappel minimal

Un ordinateur ne stocke pas les nombres en base 10 (chiffres de 0 à 9) mais en
**base 2** : uniquement des `0` et des `1`. Chaque `0` ou `1` s'appelle un **bit**.

En base 10, le nombre `253` se lit : `2×100 + 5×10 + 3×1`. Chaque position a un
poids : 1, 10, 100, 1000… (des puissances de 10).

En base 2, c'est le même principe mais les poids sont des **puissances de 2** :
1, 2, 4, 8, 16, 32, 64, 128… On va travailler sur **8 bits** (un octet), donc 8
positions.

Une position vaut soit `0` (le poids ne compte pas), soit `1` (le poids compte).

## Exercices — à faire sur papier d'abord

> Travaille sur 8 bits à chaque fois. Note le détail de ton raisonnement, pas juste
> le résultat final.

**Ex 1.** Écris les poids des 8 positions, de la plus à droite à la plus à gauche.
(Position 0 = la plus à droite. Quel est son poids ? Et les suivantes ?)

**Ex 2.** Convertis ces nombres décimaux en binaire sur 8 bits :
- `5`
- `8`
- `10`
- `255`

**Ex 3.** Convertis ces écritures binaires en décimal :
- `00000001`
- `00000100`
- `00010000`
- `10000000`

**Ex 4.** Question d'observation : regarde tes réponses de l'Ex 3. Les quatre nombres
n'ont qu'un seul bit à `1`. Quelle est la valeur décimale à chaque fois ? Tu remarques
un lien entre la **position** du `1` et la valeur ?

**Ex 5.** Quel est le plus grand nombre qu'on peut écrire sur 8 bits ? Pourquoi
celui-là et pas un de plus ?

## Zone réponses

> Écris ici tes prédictions avant qu'on vérifie ensemble.

- Ex 1 :
- Ex 2 :
- Ex 3 :
- Ex 4 :
- Ex 5 :

## Question d'ouverture (pour le module suivant)

Dans l'Ex 4, tu as vu qu'un `1` qui se déplace vers la gauche fait grandir la valeur.
À ton avis, de combien la valeur est-elle multipliée chaque fois que le `1` avance
d'**une** position vers la gauche ? Garde ton intuition en tête : c'est exactement ce
que fait l'opérateur `<<`.
