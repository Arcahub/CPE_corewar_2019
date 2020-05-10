/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** destroy
*/

#include "corewar-cli/corewar-cli.h"
#include <unistd.h>

void cw_corewar_cli_destroy(cw_corewar_cli_t *self)
{
    cw_program_def_t *prog = NULL;

    if (self == NULL)
        return;
    LIST_FOR_EACH(self->progs_list, iter) {
        prog = iter.v;
        my_free(prog->data);
        my_free(prog);
    }
    list_destroy(self->progs_list);
    my_free(self);
}