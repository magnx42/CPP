# Extra — Apprendre le bit shifting

Point de départ : en codant `toFloat()` / `toInt()` de la classe `Fixed` (CPP02/ex01),
on est tombé sur `1 << _bits`. L'opérateur `<<` n'était pas connu. Ce dossier sert à
comprendre le décalage de bits **de zéro**, à ton rythme.

## La règle du jeu

- Tu fais les exercices **sur papier d'abord** : tu prédis les résultats à la main,
  en binaire et en décimal, avant toute vérification.
- Je ne te donne **aucune réponse directe** ni aucun corrigé. Je te guide par des
  questions. Si tu bloques, je te pose une question plus petite, je ne déroule pas
  la solution à ta place.
- Chaque énoncé a une **zone réponses** vide. Tu écris tes prédictions dedans, puis
  tu me les donnes. On vérifie ensemble, on corrige, et seulement après on passe au
  module suivant.

## Ordre de la progression

1. `01-binaire-les-bases/` — comment un entier s'écrit en binaire (socle indispensable)
2. `02-left-shift/` — l'opérateur `<<`
3. `03-right-shift/` — l'opérateur `>>`
4. `04-application-fixed-point/` — on relie tout au `Fixed` de l'ex01

Fais-les **dans l'ordre**. Chaque module suppose le précédent acquis.

## Comment on démarre

Ouvre `01-binaire-les-bases/enonce.md`, fais les exercices, remplis la zone réponses,
puis dis-moi « j'ai fait le 01 ». On vérifie ensemble avant d'avancer.
