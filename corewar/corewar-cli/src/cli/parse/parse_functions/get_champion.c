/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_champion
*/

#include "corewar-cli/corewar.h"

bool cw_corewar_cli_get_champion(char **argv, usize_t *index, void *data)
{
    printf("champ: %s\n", argv[*index]);
    return (true);
}