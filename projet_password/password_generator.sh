#!/bin/bash

echo "🔐 Entrez la longueur du mot de passe : "
read LENGTH

# Générer un mot de passe aléatoire avec des lettres, chiffres et symboles
PASSWORD=$(tr -dc 'A-Za-z0-9!@#$%^&*()_+=-' </dev/urandom | head -c $LENGTH)

echo "🎉 Mot de passe généré : $PASSWORD"
