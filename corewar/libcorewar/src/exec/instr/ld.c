/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "ld" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__ld(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    u64_t a = cw_vm__exec_pval(vm, core, &instr->args[0], vm->config.reg_size);
    u64_t s = a & reg_mask(vm);

    core->regs.regs[instr->args[1].u.reg] = s;
    core->regs.zero = s == 0;
    core->regs.pc = instr->end;
}
