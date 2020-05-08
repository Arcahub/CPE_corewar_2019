/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar-cli
*/

#ifndef COREWAR_CLI_H_
#define COREWAR_CLI_H_

#include "corewar-cli/corewar.h"

typedef struct {
    cw_program_def_t *progs_list;
    usize_t prog_count;
    usize_t dump_cycles;
} cw_corewar_cli_t;

void cw_corewar_cli_init(cw_corewar_cli_t *self);
u64_t cw_corewar_cli_parse(cw_corewar_cli_t *self, char **argv, usize_t argc);

#endif /* !COREWAR_CLI_H_ */
