/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "or" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__or(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    i64_t a = cw_vm__exec_pval(vm, core, &instr->args[0], vm->config.reg_size);
    i64_t b = cw_vm__exec_pval(vm, core, &instr->args[1], vm->config.reg_size);
    i64_t or = a | b;

    core->regs.zero = or == 0;
    core->regs.regs[instr->args[2].u.reg] = or;
    core->regs.pc = instr->end;
}
