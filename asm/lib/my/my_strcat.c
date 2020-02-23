/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    int length = 0;
    int length_dest = 0;
    char *str = {0};

    length = my_strlen(src);
    length_dest = my_strlen(dest);
    str = malloc(sizeof(char) * (length + length_dest) + 1);
    for (int h = 0; h != length + length_dest + 1; h = h + 1)
        str[h] = 0;
    for (int j = 0; j < length_dest; j++)
        str[j] = dest[j];
    for (int i = 0; i < length; i++)
        str[length_dest  + i] = src[i];
    return (str);
}