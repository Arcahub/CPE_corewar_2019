/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_getline
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

char *my_get_line(FILE *fd)
{
    char *input = NULL;
    size_t size = 0;
    ssize_t read = 0;

    read = getline(&input, &size, fd);
    if (read == EOF) {
        free(input);
        return (NULL);
    }
    if (input[read - 1] == '\n')
        input[read - 1] = '\0';
    return (input);
}