/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "xor" instruction implementation
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__xor(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    (void)(vm);
    (void)(core);
    (void)(instr);
    core->regs.pc = instr->end;
}
