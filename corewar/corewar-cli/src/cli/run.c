/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** run
*/

#include "corewar-cli/corewar-cli.h"
#include "corewar-cli/corewar.h"
#include "corewar-cli/op.h"

static u64_t cw_corewar_cli_run_with_dump_cycles(cw_corewar_cli_t *self,
cw_vm_t *vm)
{
    bool exit_status = true;
    u8_t dump[MEM_SIZE];

    // exit_status = cw_vm_run(vm, self->dump_cycles);
    while (exit_status) {
        //cw_vm_memory_dump(vm, dump, MEM_SIZE);
        // exit_status = cw_vm_run(vm, self->dump_cycles);
        exit_status = false;
    }
    // cw_vm_destroy(vm);
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
    // cw_vm_destroy(vm);
    if (exit_status)
        return (0);
    return (84);
}

u64_t cw_corewar_cli_run(cw_corewar_cli_t *self)
{
    cw_vm_t *vm = NULL;
    //cw_vm_t *vm = (cw_corewar_cli_create_vm(self));

    if (vm == NULL)
        return (84);
    if (self->dump_cycles.is_some)
        return (cw_corewar_cli_run_with_dump_cycles(self, vm));
    else
        return (cw_corewar_cli_run_without_dump_cycles(self, vm));
}