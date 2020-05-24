/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** parse
*/

#include "corewar-gui/corewar-cli.h"
#include "corewar-gui/args_parser.h"
#include "priv.h"

u64_t cw_corewar_cli_parse(cw_corewar_cli_t *self, char **argv, u64_t argc)
{
    args_parser_t *parser = args_parser_init(&cw_corewar_cli_get_champion,
    self);
    u64_t exit_status = 0;

    args_parser_add_bind(parser, "-a", &cw_corewar_cli_get_champion_with_args,
    self);
    args_parser_add_bind(parser, "-n", &cw_corewar_cli_get_champion_with_args,
    self);
    exit_status = args_parser_run(parser, argv, argc, 1);
    args_parser_destroy(parser);
    return (exit_status);
}
