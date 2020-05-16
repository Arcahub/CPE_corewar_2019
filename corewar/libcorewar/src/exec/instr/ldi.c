/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "ldi" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__ldi(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    i64_t a = cw_vm__exec_pval(vm, core, &instr->args[0], vm->config.ind_size);
    i64_t b = cw_vm__exec_pval(vm, core, &instr->args[1], vm->config.ind_size);
    i64_t addr = core->regs.pc + (a + b) % vm->config.idx_mod;
    i64_t val = cw_vm__read_int(vm, addr, vm->config.reg_size);

    core->regs.zero = val == 0;
    core->regs.regs[instr->args[2].u.reg] = reg_mask(vm, val);
    core->regs.pc = instr->end;
}
