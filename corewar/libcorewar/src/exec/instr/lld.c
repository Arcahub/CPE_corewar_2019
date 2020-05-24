/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "lld" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__lld(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    i64_t a = cw_vm__exec_plval(vm, core, &instr->args[0], vm->config.reg_size);

    a = reg_mask(vm, a);
    core->regs.zero = a == 0;
    core->regs.regs[instr->args[1].u.reg] = a;
    core->regs.pc = instr->end;
}
