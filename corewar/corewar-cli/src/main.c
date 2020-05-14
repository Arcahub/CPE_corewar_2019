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
    cw_corewar_cli_t *cli = cw_corewar_cli_init();

    if (cli == NULL)
        return (84);
    if (cw_corewar_cli_parse(cli, argv, argc) == 84 ||
        cli->progs_list->len < 2) {
        cw_corewar_cli_destroy(cli);
        return (84);
    }
    cw_corewar_cli_run(cli);
    cw_corewar_cli_destroy(cli);
    return (0);
}
