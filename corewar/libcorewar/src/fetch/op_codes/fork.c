/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** fork
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw__fetch_fork(const cw_vm_t *vm, const cw_core_t *core, cw_instr_t *instr)
{
    usize_t addr = core->regs.pc + 1;
    bool err = false;

    err |= cw__fetch_read_sparam(vm, CW_PARAM_DIR, &addr, &instr->args[0]);
    instr->end = addr;
    return (err);
}
