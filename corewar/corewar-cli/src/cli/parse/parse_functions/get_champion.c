/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_champion
*/

#include "corewar-cli/corewar-cli.h"
#include "my/io.h"

bool cw_corewar_cli_get_champion(char **argv, usize_t *index, void *data)
{
    cw_corewar_cli_t *cli = data;

    return (cw_corewar_cli_add_prog(cli, NONE(u32), NONE(usize), argv[*index]));
}