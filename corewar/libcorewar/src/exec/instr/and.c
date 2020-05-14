/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "and" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__and(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    u64_t a = cw_vm__exec_pval(vm, core, &instr->args[0], vm->config.reg_size);
    u64_t b = cw_vm__exec_pval(vm, core, &instr->args[1], vm->config.reg_size);
    u64_t and = a & b;

    core->regs.zero = and == 0;
    core->regs.regs[instr->args[2].u.reg] = and;
    core->regs.pc = instr->end;
}
