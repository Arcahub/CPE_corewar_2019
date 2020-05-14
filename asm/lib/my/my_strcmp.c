/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char *str1, char *str2)
{
    return (my_strncmp(str1, str2, my_strlen(str2)));
}