/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** fetch
*/

#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"
#include "priv.h"

cw__fetch_fn_t *const FETCH_FUNCTIONS[256] = {
    NULL,
    &cw__fetch_live,
    &cw__fetch_ld,
    &cw__fetch_st,
    &cw__fetch_add,
    &cw__fetch_sub,
    &cw__fetch_and,
    &cw__fetch_or,
    &cw__fetch_xor,
    &cw__fetch_zjmp,
    &cw__fetch_ldi,
    &cw__fetch_sti,
    &cw__fetch_fork,
    &cw__fetch_lld,
    &cw__fetch_lldi,
    &cw__fetch_lfork,
    &cw__fetch_aff
};

bool cw_vm__fetch_instr(const cw_vm_t *vm, const cw_core_t *core,
    cw_instr_t *ret_instr)
{
    cw__fetch_fn_t *fn = NULL;
    bool return_code = false;

    ret_instr->opcode = vm->mem[core->regs.pc];
    fn = FETCH_FUNCTIONS[ret_instr->opcode];
    my_printf("valid_opcode fectch: %s, %d\n", fn ? "yes" : "no", core->regs.pc);
    if (!fn)
        return (true);
    else
        return_code = fn(vm, core, ret_instr);
    my_printf("return_code fectch: %s\n", return_code ? "yes" : "no");
    return (return_code);
}