/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** run
*/

#include "corewar-cli/corewar-cli.h"
#include "corewar/corewar.h"
#include "corewar-cli/op.h"

static const cw_config_t VM_CONF = {
    .prog_name_length = PROG_NAME_LENGTH,
    .comment_length = COMMENT_LENGTH,
    .corewar_exec_magic = COREWAR_EXEC_MAGIC,
    .reg_size = REG_SIZE,
    .idx_mod = IDX_MOD,
    .ind_size = IND_SIZE,
    .dir_size = DIR_SIZE,
    .mem_size = MEM_SIZE,
    .cycle_to_die = CYCLE_TO_DIE,
    .cycle_delta = CYCLE_DELTA,
    .nbr_live = NBR_LIVE
};

static u64_t cw_corewar_cli_run_with_dump_cycles(cw_corewar_cli_t *self,
    cw_vm_t *vm)
{
    bool exit_status = true;

    // exit_status = cw_vm_run(vm, self->dump_cycles);
    while (exit_status) {
        cw_vm_memory_dump(vm);
        // exit_status = cw_vm_run(vm, self->dump_cycles);
        exit_status = false;
    }
    cw_vm_destroy(vm);
    if (exit_status)
        return (0);
    return (84);
}

static u64_t cw_corewar_cli_run_without_dump_cycles(cw_corewar_cli_t *self,
    cw_vm_t *vm)
{
    bool exit_status = true;

    (void) self;
    // exit_status = cw_vm_run(vm, self->dump_cycles);
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

    if (progs_list == NULL)
        return (NULL);
    LIST_FOR_EACH(cli->progs_list, iter) {
        prog = iter.v;
        progs_list[index] = *prog;
        index++;
    }
    return (cw_vm_new(&VM_CONF, progs_list, cli->progs_list->len));
}

u64_t cw_corewar_cli_run(cw_corewar_cli_t *self)
{
    cw_vm_t *vm = cw_corewar_cli_create_vm(self);

    if (vm == NULL)
        return (84);
    // This has been forced to true because the parser has a problem
    if (self->dump_cycles.is_some)
        return (cw_corewar_cli_run_with_dump_cycles(self, vm));
    else
        return (cw_corewar_cli_run_without_dump_cycles(self, vm));
}
