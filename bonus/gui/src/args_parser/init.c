/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init
*/

#include "corewar-gui/args_parser.h"
#include "my/my.h"

args_parser_t *args_parser_init(arg_callback_t *default_callback, void *data)
{
    args_parser_t *parser = my_malloc(sizeof(args_parser_t));

    if (parser == NULL || default_callback == NULL) {
        my_free(parser);
        return (NULL);
    }
    parser->callback_list = list_new();
    if (!parser->callback_list) {
        my_free(parser);
        return (NULL);
    }
    parser->default_exec.arg = NULL;
    parser->default_exec.callback = default_callback;
    parser->default_exec.data = data;
    return (parser);
}
