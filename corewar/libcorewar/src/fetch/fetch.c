/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** fetch
*/

#include "corewar.h"
#include "instr.h"
#include "priv.h"

const cw_fetch_fn_t FETCH_FUNCTIONS[256] = {
    NULL,
    &cw_fetch_live,
    &cw_fetch_ld,
    &cw_fetch_st,
    &cw_fetch_add,
    &cw_fetch_sub,
    &cw_fetch_and,
    &cw_fetch_or,
    &cw_fetch_xor,
    &cw_fetch_zjmp,
    &cw_fetch_ldi,
    &cw_fetch_sti,
    &cw_fetch_fork,
    &cw_fetch_lld,
    &cw_fetch_lldi,
    &cw_fetch_lfork,
    &cw_fetch_aff
};

bool cw_instruction_fetch(cw_vm_t *vm, cw_core_t *current_core,
    cw_instr_t *ret_instr)
{
    cw_instr_t ret_instr = {0};
    cw_fetch_fn_t *fn = NULL;
    bool return_code = false;

    ret_instr->opcode = vm->mem[current_core->regs.pc];
    fn = FETCH_FUNCTIONS[ret_instr->opcode];
    if (!fn)
        return_code = cw_fetch_fallback(vm, current_core, &ret_instr);
    else
        return_code = fn(vm, current_core, &ret_instr);
    return (return_code);
}
