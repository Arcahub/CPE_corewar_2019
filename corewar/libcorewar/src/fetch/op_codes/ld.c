/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** ld
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_ld(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    instr->args.ld.src.type = vm->mem[current_core->regs.pc++];
    switch (instr->args.ld.src.type) {
    case CW_RVAL_REG:
        break;
    case CW_RVAL_DIR:
        break;
    case CW_RVAL_IND:
        break;
    default:
        return (true);
    }
    instr->args.ld.dst = vm->mem[current_core->regs.pc++];
    return (false);
}
