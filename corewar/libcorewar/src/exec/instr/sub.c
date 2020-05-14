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
    u64_t a = cw_vm__exec_pget(core, &instr->args[0]);
    u64_t b = cw_vm__exec_pget(core, &instr->args[1]);

    core->regs.regs[instr->args[2].u.reg] = (a - b) & reg_mask(vm);
    core->regs.pc = instr->end;
}
