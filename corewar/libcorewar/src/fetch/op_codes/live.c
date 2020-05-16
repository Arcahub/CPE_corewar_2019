/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** live
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw__fetch_live(const cw_vm_t *vm, const cw_core_t *core, cw_instr_t *instr)
{
    instr->args[0].type = CW_PARAM_DIR;
    instr->args[0].u.val = cw_vm__read_int(vm, core->regs.pc + 1, 4);
    instr->end = core->regs.pc + 5;
    return (false);
}
