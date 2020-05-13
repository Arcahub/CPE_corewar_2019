/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** lfork
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw__fetch_lfork(const cw_vm_t *vm, const cw_core_t *core,
    cw_instr_t *instr)
{
    usize_t addr = core->regs.pc + 1;

    instr->args[0] = cw__fetch_read_param(vm, core, CW_PARAM_IND, &addr);
    instr->end = addr;
    return (false);
}
