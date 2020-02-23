/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** my_strndup
*/

#include <stdlib.h>

char *my_strndup(char *str, int n)
{
    char *cpy = malloc(sizeof(char) * (n + 1));

    if (cpy == NULL)
        return (NULL);
    for (int i = 0; i < n; i++)
        cpy[i] = str[i];
    cpy[n] = '\0';
    return (cpy);
}