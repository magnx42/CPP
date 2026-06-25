# Module 02 — Le décalage à gauche `<<`

## Objectif

Comprendre ce que fait l'opérateur `<<` (left shift) sur les bits d'un entier, et
découvrir par toi-même la règle qui le relie à une multiplication.

## Rappel minimal

`x << n` veut dire : « prends l'écriture binaire de `x`, et décale tous ses bits de
`n` positions vers la **gauche** ». Les positions libérées à droite sont remplies par
des `0`.

Exemple de mécanique (pas de résultat donné, juste le geste) :

```
00000011   ← un nombre quelconque sur 8 bits
?               décale chaque bit d'une position vers la gauche
00000110   ← le résultat (les bits ont bougé, un 0 est entré à droite)
```

C'est tout ce que fait `<< 1`. Faire `<< 3`, c'est répéter le geste 3 fois.

## Exercices — à faire sur papier d'abord

> Pour chaque exercice : écris d'abord l'opérande en binaire 8 bits, applique le
> décalage bit par bit, puis reconvertis en décimal.

**Ex 1.** Prédis le résultat (en binaire ET en décimal) de :
- `1 << 0`
- `1 << 1`
- `1 << 3`
- `1 << 8`  *(attention : combien de bits faut-il pour écrire ce résultat ?)*

**Ex 2.** Même chose avec un opérande qui a plusieurs bits à `1` :
- `5 << 1`
- `3 << 4`

**Ex 3.** Pour chaque résultat de l'Ex 1, calcule à part : par combien `1` a-t-il été
multiplié ? (compare le résultat à l'opérande de départ). Tu vois une règle se
dessiner ? Essaie de l'écrire sous la forme `x << n == ...`.

**Ex 4.** Vérifie ta règle sur l'Ex 2 : est-ce que `5 << 1` et `3 << 4` collent avec
la formule que tu as proposée à l'Ex 3 ?

**Ex 5 — débordement.** On travaille toujours sur 8 bits (valeurs de 0 à 255).
Prédis ce qui se passe pour `1 << 8` si on n'avait QUE 8 bits de rangement.
Où va le bit qui devrait se trouver en position 8 ? Que devient la valeur ?

**Ex 6 — le lien avec ton code.** Dans `Fixed`, on écrit `1 << _bits` avec
`_bits = 8`. D'après ta règle de l'Ex 3, quelle valeur décimale ça produit ?
Pourquoi on n'écrit pas juste `256` directement, à ton avis ?

## Zone réponses

- Ex 1 :
- Ex 2 :
- Ex 3 (ta règle) :
- Ex 4 :
- Ex 5 :
- Ex 6 :

## Question d'ouverture (pour le module suivant)

Si décaler à **gauche** multiplie, qu'est-ce que décaler à **droite** (`>>`) devrait
faire à ton avis ? Et une intuition à creuser : que devient la partie qui « tombe »
à droite quand on décale dans ce sens ?
