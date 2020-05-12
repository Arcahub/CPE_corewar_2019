/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** utils
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "priv.h"

bool cw_fetch_utils_populate_rvalue(cw_vm_t *vm, cw_core_t *current_core,
    cw_param_t *param)
{
    usize_t addr = current_core->regs.pc % vm->config.mem_size;

    switch (param->type) {
    case CW_PARAM_IND:
        param->u.ind = 0;
        my_memcpy(&param->u.ind, &vm->mem[addr], vm->config.ind_size);
        current_core->regs.pc += vm->config.ind_size;
        param->u.ind = u64_be_to_ne(param->u.ind);
        return (false);
    case CW_PARAM_DIR:
        param->u.dir = 0;
        my_memcpy(&param->u.dir, &vm->mem[addr], vm->config.dir_size);
        current_core->regs.pc += vm->config.dir_size;
        param->u.dir = u64_be_to_ne(param->u.dir);
        return (false);
    case CW_PARAM_REG:
        param->u.reg = vm->mem[current_core->regs.pc++];
        return (false);
    }
    return (true);
}
