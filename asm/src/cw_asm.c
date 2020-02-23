/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm
*/

#include <stdio.h>
#include "cw_asm.h"

int cw_asm(int argc, char **argv)
{
    FILE *fdin = 0;
    int fdout = 0;

    if (argc != 2)
        return (84);
    if (cw_asm_check_file(argv[1], &fdin))
        return (84);
    fdout = cw_asm_create_output(argv[1]);
    if (fdout < 0)
        return (84);
    return (cw_asm_compile(fdin, fdout));
}