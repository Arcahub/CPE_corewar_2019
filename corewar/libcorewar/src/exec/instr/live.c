/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "live" instruction implementation
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__live(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    core->regs.pc = instr->end;
    core->state.age = 0;
    vm->state.live_calls++;
    if (vm->state.live_calls >= vm->config.nbr_live && vm->cores->len > 1) {
        vm->cycle_to_die -= u64_min(vm->cycle_to_die, vm->config.cycle_delta);
        vm->state.live_calls = 0;
        core->state.owner = cw_vm__exec_pget(core, &instr->args[0]);
    }
}
