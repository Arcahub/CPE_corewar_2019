/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** main
*/

#include <stdbool.h>
#include "corewar-gui/corewar.h"
#include "corewar-gui/corewar-cli.h"
#include "corewar-gui/args_parser.h"
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