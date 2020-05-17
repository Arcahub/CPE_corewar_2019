/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** run
*/

#include <unistd.h>
#include "corewar-gui/corewar-cli.h"
#include "corewar-gui/corewar.h"
#include "corewar-gui/op.h"
#include "corewar-gui/gui.h"

static const cw_config_t VM_CONF = {
    .prog_name_length = PROG_NAME_LENGTH,
    .comment_length = COMMENT_LENGTH,
    .corewar_exec_magic = COREWAR_EXEC_MAGIC,
    .reg_size = REG_SIZE,
    .reg_count = REG_NUMBER,
    .idx_mod = IDX_MOD,
    .ind_size = IND_SIZE,
    .dir_size = DIR_SIZE,
    .mem_size = MEM_SIZE,
    .cycle_to_die = CYCLE_TO_DIE,
    .cycle_delta = CYCLE_DELTA,
    .nbr_live = NBR_LIVE,
};

static u64_t cw_corewar_cli_run_without_dump_cycles(cw_corewar_cli_t *self,
    cw_vm_t *vm, cg_ui_t *ui)
{
    bool exit_status = true;

    (void)(self);
    while (true) {
        cw_vm_run(vm, SOME(u64, 10));
        cg_ui_update(ui, vm);
        usleep(100000);
    }
    cw_vm_destroy(vm);
    if (exit_status)
        return (0);
    return (84);
}

cw_vm_t *cw_corewar_cli_create_vm(cw_corewar_cli_t *cli)
{
    cw_program_def_t *progs_list = my_malloc(sizeof(cw_program_def_t) *
        cli->progs_list->len);
    cw_program_def_t *prog = NULL;
    usize_t index = 0;
    cw_vm_t *vm = NULL;

    if (progs_list == NULL)
        return (NULL);
    LIST_FOR_EACH(cli->progs_list, iter) {
        prog = iter.v;
        progs_list[index++] = *prog;
    }
    vm = cw_vm_new(&VM_CONF);
    cw_vm_load_programs(vm, progs_list, cli->progs_list->len);
    return (vm);
}

u64_t cw_corewar_cli_run(cw_corewar_cli_t *self)
{
    cw_vm_t *vm = cw_corewar_cli_create_vm(self);
    cg_ui_t *ui = cg_ui_init();

    if (vm == NULL)
        return (84);
    cw_corewar_cli_run_without_dump_cycles(self, vm, ui);
    return (0);
}
