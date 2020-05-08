/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cli
*/

#include "corewar-cli/corewar-cli.h"
#include "corewar-cli/args_parser.h"
#include "my/io.h"

int main(int argc, char **argv)
{
    cw_corewar_cli_t cli;

    cw_corewar_cli_init(&cli);
    if (cw_corewar_cli_parse(&cli, argv, argc) == 84)
        return (84);
    //cw_corewar_cli_create_vm(&cli);
    //cw_corewar_cli_run(&cli);
    //cw_corewar_cli_end(&cli);
    return (0);
}