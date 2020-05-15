/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** zjmp
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw__fetch_zjmp(const cw_vm_t *vm, const cw_core_t *core,
    cw_instr_t *instr)
{
    usize_t addr = core->regs.pc + 1;
    bool err = false;

    err |= cw__fetch_read_param(vm, CW_PARAM_IND, &addr, &instr->args[0]);
    instr->end = addr;
    return (err);
}
