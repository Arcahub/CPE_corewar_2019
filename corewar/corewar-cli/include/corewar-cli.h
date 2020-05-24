/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar-cli
*/

#ifndef COREWAR_CLI_H_
#define COREWAR_CLI_H_

#include "corewar/corewar.h"

typedef struct {
    list_t *progs_list;
    OPT(u64) dump_cycles;
} cw_corewar_cli_t;

cw_corewar_cli_t *cw_corewar_cli_init();
u64_t cw_corewar_cli_parse(cw_corewar_cli_t *self, char **argv, usize_t argc);
bool cw_corewar_cli_add_prog(cw_corewar_cli_t *self, OPT(u32) prog_number,
    OPT(usize) load_address, const char *filepath);
u64_t cw_corewar_cli_run(cw_corewar_cli_t *self);
void cw_corewar_cli_destroy(cw_corewar_cli_t *self);
void cw_corewar_cli_dump(cw_vm_t *vm);
void cw_corewar_cli_setup_callbacks(cw_vm_t *vm);
void cw_corewar_cli_print_winner(cw_vm_t *vm);

#endif /* !COREWAR_CLI_H_ */
