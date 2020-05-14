/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "st" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__st(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    u64_t a = cw_vm__exec_pget(core, &instr->args[0]);

    if (instr->args[1].type == CW_PARAM_REG)
        core->regs.regs[instr->args[1].u.reg] = a;
    else
        vm->mem[core->regs.pc + instr->args[1].u.val % vm->config.idx_mod %
            vm->config.mem_size] = a;
    core->regs.pc = instr->end;
}
