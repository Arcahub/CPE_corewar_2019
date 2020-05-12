/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** utils
*/

#include "corewar/corewar.h"

bool cw_fetch_utils_populate_rvalue(cw_vm_t *vm, cw_core_t *current_core,
    cw_rvalue_t *r_value)
{
    switch (r_value->type) {
    case CW_RVAL_IND:
        r_value->u.ind = &vm->mem[current_core->regs.pc % vm->config.mem_size];
        current_core->regs.pc += (vm->config.ind_size);
        break;
    case CW_RVAL_DIR:
        r_value->u.dir = &vm->mem[current_core->regs.pc % vm->config.mem_size];
        current_core->regs.pc += (vm->config.dir_size);
        break;
    case CW_RVAL_REG:
        r_value->u.reg = vm->mem[current_core->regs.pc++];
        break;
    default:
        return (true);
    }
    return (false);
}