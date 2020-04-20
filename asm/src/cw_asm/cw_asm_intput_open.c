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

FILE *cw_asm_input_open(char *path)
{
    FILE *fdin = NULL;

    if (path == NULL)
        return (NULL);
    fdin = fopen(path, "r");
    if (fdin == NULL)
        return (NULL);
    return (fdin);
}