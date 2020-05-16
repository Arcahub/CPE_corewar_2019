/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "lfork" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"
#include "../../priv.h"

void cw_vm__exec__lfork(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    i64_t a = cw_vm__exec_pget(core, &instr->args[0]);

    cw_vm__add_core(vm, (core->regs.pc + a) % vm->config.mem_size,
        SOME(cw_core, *core));
    core->regs.pc = instr->end;
}
