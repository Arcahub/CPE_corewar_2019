/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_findchr
*/

#include <stdbool.h>

bool my_findchr(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (true);
    return (false);
}