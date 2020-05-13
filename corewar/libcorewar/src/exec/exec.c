/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Instruction execution
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"
#include "priv.h"

static exec_instr_fn_t *const CALLBACKS[256] = {
    NULL,
    &cw_vm__exec__live,
    &cw_vm__exec__ld,
    &cw_vm__exec__st,
    &cw_vm__exec__add,
    &cw_vm__exec__sub,
    &cw_vm__exec__and,
    &cw_vm__exec__or,
    &cw_vm__exec__xor,
    &cw_vm__exec__zjmp,
    &cw_vm__exec__ldi,
    &cw_vm__exec__sti,
    &cw_vm__exec__fork,
    &cw_vm__exec__lld,
    &cw_vm__exec__lldi,
    &cw_vm__exec__lfork,
    &cw_vm__exec__aff
};

void cw_vm__exec_instr(cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr)
{
    exec_instr_fn_t *fn = CALLBACKS[instr->opcode];

    if (fn != NULL)
        fn(vm, core, instr);
}
