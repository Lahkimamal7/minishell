Projet : Générateur de mot de passe sécurisé  
Étudiante : LAHKIM Amal
Filière : Biostatistique Démographie et Big Data  
Date : 25 mai 2025

Objectif :
Ce script bash permet de générer un mot de passe sécurisé aléatoire, avec une longueur définie par l'utilisateur. Mais j’ai rencontré un problème où ça n’a pas pu marcher au début mais le deuxième screen montre que cela a finalement bien fonctionné.

Fonctionnement :
- Le script demande à l'utilisateur de saisir une longueur.
- Il utilise ‘/dev/urandom’ pour générer des caractères aléatoires.
- Il filtre les caractères avec ‘tr’.
- Il affiche un mot de passe aléatoire de la longueur choisie.

Commandes utilisées :
- `read` : pour lire l’entrée utilisateur
- `tr` : pour filtrer les caractères
- `head` : pour prendre les premiers caractères
- `/dev/urandom` : source de données aléatoires
- `echo` : pour afficher les résultats

Utilisation :
```bash 
chmod +x password_generator.sh
./password_generator.sh
