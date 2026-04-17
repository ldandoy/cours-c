# Exercice — Gestion d’un accueil avec file et historique avec pile

## Énoncé

On souhaite gérer les visiteurs d’un guichet.

Chaque visiteur est représenté par un numéro entier.

Le programme doit afficher un menu :

1 - Ajouter un visiteur dans la file
2 - Appeler le prochain visiteur
3 - Afficher la file d'attente
4 - Afficher l'historique des visiteurs traités
5 - Annuler le dernier visiteur traité
6 - Quitter


## Règles

- Quand un visiteur arrive, on l’ajoute à la file.
- Quand on appelle un visiteur :
- on retire le premier élément de la file
- on l’ajoute dans la pile des visiteurs traités
- Quand on annule le dernier visiteur traité :
- on retire le sommet de la pile
- on réinsère ce visiteur dans la file

## Travail demandé

- Utiliser la structure de file définie dans files.h / files.c.
- Utiliser aussi une structure de pile.
- Écrire un programme principal avec un menu en boucle.
- Gérer les erreurs :
    - file vide
    - pile vide