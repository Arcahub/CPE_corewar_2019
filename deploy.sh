##
## EPITECH PROJECT, 2020
## minishell1
## File description:
## deploy
##

NAME=$TRAVIS_REPO_SLUG
REPO_NAME=$(echo -n $NAME | awk -F'/' '{print $2}')

ssh-keyscan -H git.epitech.eu >> ~/.ssh/known_hosts
git push git@git.epitech.eu:/guillaume.mailhol@epitech.eu/$REPO_NAME master