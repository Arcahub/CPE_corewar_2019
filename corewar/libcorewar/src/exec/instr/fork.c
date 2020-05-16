/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "fork" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"
#include "../../priv.h"

void cw_vm__exec__fork(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    i64_t a = cw_vm__exec_pget(core, &instr->args[0]);

    cw_vm__add_core(vm, cw_vm_compute_addr(vm, core->regs.pc + a %
        vm->config.idx_mod), SOME(cw_core, *core));
    if (core->regs.regs[0] == 0)
        return (false);
    core->regs.pc = instr->end;
}
