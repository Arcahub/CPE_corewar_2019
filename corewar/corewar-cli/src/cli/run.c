/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** run
*/

#include "my/io.h"
#include "corewar-cli/corewar-cli.h"
#include "corewar/corewar.h"
#include "corewar-cli/op.h"

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

void cw_corewar_cli_print_winner(cw_vm_t *vm)
{
    u64_t count = 0;
    u64_t prog_number = 0;
    usize_t last_live = 0;

    for (u64_t i = 0; i < vm->prog_count; i++) {
        if (vm->programs[i].last_live > last_live) {
            prog_number = i;
            last_live = vm->programs[i].last_live;
            count = 0;
        } else if (vm->programs[i].last_live == last_live)
            count += 1;
    }
    if (count != 0)
        return;
    my_printf("The player %d(%s)has won.\n", prog_number + 1,
        vm->programs[prog_number].name);
}

static u64_t cw_corewar_cli_run_with_dump_cycles(cw_corewar_cli_t *self,
    cw_vm_t *vm)
{
    bool exit_status = true;

    while (exit_status) {
        exit_status = cw_vm_run(vm, self->dump_cycles);
        cw_corewar_cli_dump(vm);
    }
    cw_corewar_cli_print_winner(vm);
    cw_vm_destroy(vm);
    if (exit_status)
        return (0);
    return (84);
}

static u64_t cw_corewar_cli_run_without_dump_cycles(cw_corewar_cli_t *self,
    cw_vm_t *vm)
{
    bool exit_status = true;

    (void)(self);
    exit_status = cw_vm_run(vm, self->dump_cycles);
    cw_corewar_cli_print_winner(vm);
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
        progs_list[index] = *prog;
        index++;
    }
    vm = cw_vm_new(&VM_CONF);
    if (!vm || cw_vm_load_programs(vm, progs_list, cli->progs_list->len)) {
        cw_vm_destroy(vm);
        return (NULL);
    }
    return (vm);
}

u64_t cw_corewar_cli_run(cw_corewar_cli_t *self)
{
    cw_vm_t *vm = cw_corewar_cli_create_vm(self);

    if (vm == NULL)
        return (84);
    cw_corewar_cli_setup_callbacks(vm);
    if (self->dump_cycles.is_some)
        return (cw_corewar_cli_run_with_dump_cycles(self, vm));
    else
        return (cw_corewar_cli_run_without_dump_cycles(self, vm));
}
