/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_corewar_cli_init
*/

#include "corewar-cli/corewar-cli.h"
#include "my/my.h"

cw_corewar_cli_t * cw_corewar_cli_init()
{
    cw_corewar_cli_t *self = my_malloc(sizeof(cw_corewar_cli_t));

    if (self == NULL)
        return (NULL);
    self->dump_cycles = NONE(u64);
    self->progs_list = list_new();
    if (self->progs_list == NULL) {
        my_free(self);
        return (NULL);
    }
    return (self);
}