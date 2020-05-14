/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_dump_cycles
*/

#include "corewar-cli/corewar-cli.h"
#include "my/my.h"
#include "my/io.h"

bool cw_corewar_cli_get_dump_cycles(char **argv, usize_t *index, void *data)
{
    my_opt__u64_t *dump_cycles = data;

    if (argv[*index + 1] == NULL || !my_cstr_isnum(argv[*index + 1]))
        return (false);
    *dump_cycles = SOME(u64, my_cstr_getnbr(argv[*index + 1]));
    *index += 1;
    return (true);
}
