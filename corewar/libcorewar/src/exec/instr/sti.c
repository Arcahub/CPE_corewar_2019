/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "sti" instruction implementation
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__sti(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    i64_t val = cw_vm__exec_pget(core, &instr->args[0]);
    i64_t a = cw_vm__exec_pval(vm, core, &instr->args[1], vm->config.ind_size);
    i64_t b = cw_vm__exec_pval(vm, core, &instr->args[2], vm->config.ind_size);
    i64_t dst = core->regs.pc + (a + b) % vm->config.idx_mod;

    cw_vm__write_int(vm, val, dst, vm->config.reg_size);
    core->regs.pc = instr->end;
}
