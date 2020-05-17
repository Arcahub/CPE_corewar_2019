/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar-cli parse priv
*/

#ifndef COREWAR_CLI_PARSE_PRIV_H_
#define COREWAR_CLI_PARSE_PRIV_H_

#include "my/my.h"

bool cw_corewar_cli_get_champion(char **argv, usize_t *index, void *data);
bool cw_corewar_cli_get_champion_with_args(char **argv, usize_t *index,
    void *data);
bool cw_corewar_cli_get_dump_cycles(char **argv, usize_t *index, void *data);

#endif /* !PRIV_H_ */
