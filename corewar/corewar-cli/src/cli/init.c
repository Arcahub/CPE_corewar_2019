/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_corewar_cli_init
*/

#include "corewar-cli/corewar-cli.h"

void cw_corewar_cli_init(cw_corewar_cli_t *self)
{
    self->dump_cycles = -1;
    self->prog_count = 0;
    self->progs_list = NULL;
}