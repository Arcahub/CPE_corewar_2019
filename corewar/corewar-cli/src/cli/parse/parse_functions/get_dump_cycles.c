/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_dump_cycles
*/

#include "my/my.h"

bool cw_corewar_cli_get_dump_cycles(char **argv, usize_t *index, void *data)
{
    if (argv[*index + 1] == NULL || !my_cstr_isnum(argv[*index + 1]))
        return (false);
    printf("-d: %s\n", argv[*index + 1]);
    *index += 1;
    return (true);
}