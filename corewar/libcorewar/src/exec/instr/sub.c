/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "sub" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__sub(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    u64_t mask = CW__REG_MASK[vm->config.reg_size];
    u64_t a = core->regs.regs[instr->args[0].u.reg] & mask;
    u64_t b = core->regs.regs[instr->args[1].u.reg] & mask;
    u64_t *c = &core->regs.regs[instr->args[2].u.reg];

    *c = (a - b) & mask;
}
