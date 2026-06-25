# Module 03 — Le décalage à droite `>>`

## Objectif

Comprendre l'opérateur `>>` (right shift), le miroir du `<<`, et surtout comprendre
ce qui se passe quand des bits « tombent » à droite (la troncature).

## Rappel minimal

`x >> n` décale tous les bits de `x` de `n` positions vers la **droite**. Les bits qui
sortent par la droite sont **perdus** (ils disparaissent, ils ne reviennent pas).

```
00001100   ← un nombre quelconque
?               décale chaque bit d'une position vers la droite
00000110   ← le résultat (un bit est sorti à droite et a disparu)
```

Note bien le « disparaissent » : c'est le point clé de ce module.

## Exercices — à faire sur papier d'abord

> Même méthode : binaire 8 bits, applique le décalage, reconvertis en décimal.

**Ex 1.** Prédis le résultat (binaire + décimal) de :
- `256 >> 8`
- `8 >> 1`
- `8 >> 3`

**Ex 2.** À partir de l'Ex 1, devine la règle. Si `<<` multipliait par `2^n`, par
quoi `>>` divise-t-il ? Écris-la sous la forme `x >> n == ...`.

**Ex 3 — la troncature.** Prédis `7 >> 1`.
- Écris `7` en binaire, décale d'une position à droite, note quel bit tombe.
- Reconvertis le résultat en décimal.
- D'après ta règle de l'Ex 2, `7 >> 1` « devrait » donner combien mathématiquement ?
- Pourquoi le résultat réel n'est PAS ça ? Qu'est devenue la différence ?

**Ex 4.** Même travail avec `10 >> 1` et `11 >> 1`. Compare les deux : pourquoi
donnent-ils le même résultat alors que `10 ≠ 11` ?

**Ex 5 — le lien avec ton code.** Dans `toInt()` on écrit `_value >> _bits`
(donc `>> 8`). Si `_value` vaut `10860` (la valeur stockée pour `42.42`),
qu'est-ce que `10860 >> 8` donne d'après ta règle ? Et pourquoi c'est cohérent avec
le fait que `toInt()` doit renvoyer la partie entière ?

## Zone réponses

- Ex 1 :
- Ex 2 (ta règle) :
- Ex 3 :
- Ex 4 :
- Ex 5 :

## Question d'ouverture (pour le module suivant)

Tu as maintenant les deux gestes : `<<` multiplie, `>>` divise (en tronquant).
Dernière étape : pourquoi la classe `Fixed` a-t-elle besoin des **deux** ? Qu'est-ce
qu'on gagne à stocker `valeur × 256` au lieu de la valeur directement ?
