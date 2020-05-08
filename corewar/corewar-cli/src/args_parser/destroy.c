/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** destroy
*/

#include "corewar-cli/args_parser.h"
#include "my/my.h"

void args_parser_destroy(args_parser_t *self)
{
    arg_bind_t *bind = NULL;

    if (!self)
        return;
    LIST_FOR_EACH(self->callback_list, iter) {
        bind = (arg_bind_t *) iter.v;
        my_free(bind->arg);
        my_free(bind);
    }
    list_destroy(self->callback_list);
    my_free(self);
}