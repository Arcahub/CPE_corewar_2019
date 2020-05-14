/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "zjmp" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__zjmp(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    u64_t a = cw_vm__exec_pget(core, &instr->args[0]);

    core->regs.pc = (core->regs.pc + a % vm->config.idx_mod) %
        vm->config.mem_size;
}
