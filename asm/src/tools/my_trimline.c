/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_trimline
*/

#include "my/my.h"
#include <stdlib.h>

char *my_trimline(char *line)
{
    char *res = NULL;
    int j = 0;

    res = my_malloc(sizeof(char) * (my_cstrlen(line) + 1));
    for (usize_t h = 0; h < my_cstrlen(line) + 1; h++)
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
