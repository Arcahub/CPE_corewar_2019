/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** args_parser
*/

#ifndef ARGS_PARSER_H_
#define ARGS_PARSER_H_

#include "my/collections/list.h"

typedef bool (arg_callback_t)(char **argv, usize_t *arg_index, void *data);

typedef struct {
    char *arg;
    arg_callback_t *callback;
    void *data;
} arg_bind_t;

typedef struct {
    list_t *callback_list;
    arg_bind_t default_exec;
} args_parser_t;

args_parser_t *args_parser_init(arg_callback_t *default_callback, void *data);
void args_parser_destroy(args_parser_t *self);

bool args_parser_add_bind(args_parser_t *self, char *arg,
    arg_callback_t *callback, void *data);

u64_t args_parser_run(args_parser_t *self, char **argv, u64_t argc,
    usize_t start);

#endif /* !ARGS_PARSER_H_ */
