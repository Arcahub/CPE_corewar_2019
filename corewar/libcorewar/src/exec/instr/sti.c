/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "sti" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"
#include "my/math.h"

void cw_vm__exec__sti(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    u64_t a = cw_vm__exec_pval(vm, core, &instr->args[1], vm->config.ind_size);
    u64_t b = cw_vm__exec_pval(vm, core, &instr->args[2], vm->config.ind_size);
    union {
        u64_t u64;
        u8_t bytes[8];
    } val = {0};
    u64_t size = u64_min(vm->config.reg_size, 8);
    u64_t max = core->regs.pc + (a +b) % vm->config.idx_mod + size;
    u64_t j = 0;

    val.u64 = cw_vm__exec_pget(core, &instr->args[0]);
    val.u64 = u64_ne_to_be(val.u64);
    for (u64_t i = core->regs.pc + (a + b) % vm->config.idx_mod; i < size;
        i++, j++)
        vm->mem[i % vm->config.mem_size] = val.bytes[j];
    core->regs.pc = instr->end;
}
