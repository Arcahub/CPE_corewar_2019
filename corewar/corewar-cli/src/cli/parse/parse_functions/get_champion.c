/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_champion
*/

#include "corewar-cli/corewar.h"
#include "corewar-cli/corewar-cli.h"
#include "my/io.h"

bool cw_corewar_cli_get_champion(char **argv, usize_t *index, void *data)
{
    cw_corewar_cli_t *cli = data;

    (void) cli;
    my_printf("champ: %s\n", argv[*index]);
    return (true);
}