/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** args_parser_run
*/

#include "corewar-cli/args_parser.h"
#include "my/my.h"
#include "my/io.h"

static int args_parser_exec_bind(args_parser_t *self, char **argv, usize_t *index)
{
    arg_bind_t *bind = NULL;
    bool exit_status = false;

    LIST_FOR_EACH(self->callback_list, iter) {
        bind = iter.v;
        if (my_cstreq(bind->arg, argv[*index])) {
            exit_status = bind->callback(argv, index, bind->data);
            return ((exit_status) ? 0 : 84);
        }
    }
    return (true);
}

usize_t args_parser_run(args_parser_t *self, char **argv, u64_t argc,
u64_t start)
{
    u64_t exit_status = 0;

    for (u64_t i = start; i < argc && argv[i]; i++) {
        exit_status = args_parser_exec_bind(self, argv, &i);
        if (exit_status == 84)
            return (84);
        else if(exit_status == 1)
            self->default_exec.callback(argv, &i, self->default_exec.data);
    }
    return (0);
}