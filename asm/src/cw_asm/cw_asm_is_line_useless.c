/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_is_line_useless
*/

#include "asm/cw_asm.h"

bool cw_asm_is_line_useless(char *line)
{
    while (*line == '\t' || *line == ' ')
        line += 1;
    if (*line == '\0' || *line == '#')
        return (true);
    return (false);
}
