/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_check_file
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

bool cw_asm_check_file(char *path, FILE **fd)
{
    if (path == NULL)
        return (true);
    *fd = fopen(path, "r");
    if (*fd == NULL)
        return (true);
    return (false);
}