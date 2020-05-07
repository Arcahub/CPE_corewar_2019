/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_trimline
*/

#include "my.h"
#include <stdlib.h>

char *my_trimline(char *line)
{
    char *res = NULL;
    int j = 0;

    res = malloc(sizeof(char) * (my_strlen(line) + 1));
    for (int h = 0; h < my_strlen(line) + 1; h++)
        res[h] = '\0';
    if (res == NULL)
        return (NULL);
    for (int i = 0; line[i]; i++)
        if (!(line[i] == ' ' || line[i] == '\t')) {
            res[j] = line[i];
            j++;
        }
    return (res);
}