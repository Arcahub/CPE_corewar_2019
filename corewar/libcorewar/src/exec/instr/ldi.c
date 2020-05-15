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
    i16_t a = cw_vm__exec_pval(vm, core, &instr->args[0], vm->config.ind_size);
    i16_t b = cw_vm__exec_pval(vm, core, &instr->args[1], vm->config.ind_size);
    i32_t s = a + b;
    union {
        u64_t u64;
        u8_t bytes[8];
    } val = {0};

    for (usize_t i = core->regs.pc; i < core->regs.pc + vm->config.reg_size;
        i++)
        val.bytes[i] = vm->mem[(s % vm->config.idx_mod + i) %
            vm->config.mem_size];
    val.u64 = u64_be_to_ne(val.u64) >> (64 - 8 * vm->config.reg_size);
    core->regs.zero = s == 0;
    core->regs.regs[instr->args[2].u.reg] = val.u64 & reg_mask(vm);
    core->regs.pc = instr->end;
}
