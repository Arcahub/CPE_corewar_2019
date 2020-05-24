/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add_bind
*/

#include "corewar-gui/args_parser.h"
#include "my/my.h"

bool args_parser_add_bind(args_parser_t *self, char *arg,
    arg_callback_t *callback, void *data)
{
    arg_bind_t *bind = my_malloc(sizeof(arg_bind_t));

    if (arg == NULL || callback == NULL || bind == NULL) {
        my_free(bind);
        return (false);
    }
    bind->arg = my_cstrdup(arg);
    bind->callback = callback;
    bind->data = data;
    if (bind->arg == NULL || list_push_front(self->callback_list, bind)) {
        my_free(bind->arg);
        my_free(bind);
        return (false);
    }
    return (true);
}
