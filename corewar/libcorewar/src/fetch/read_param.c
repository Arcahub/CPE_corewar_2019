/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Read parameters
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "priv.h"

bool cw__fetch_read_param(const cw_vm_t *vm, cw_param_type_t type,
    usize_t *addr, cw_param_t *param)
{
    param->type = type;
    switch (type) {
    case CW_PARAM_REG:
        param->u.reg = vm->mem[*addr % vm->config.mem_size] - 1;
        (*addr)++;
        if (param->u.reg >= vm->config.reg_count)
            return (true);
        break;
    case CW_PARAM_DIR:
        param->u.val = cw_vm__read_int(vm, *addr, vm->config.dir_size);
        *addr += vm->config.dir_size;
        break;
    case CW_PARAM_IND:
        param->u.val = cw_vm__read_int(vm, *addr, vm->config.ind_size);
        *addr += vm->config.ind_size;
        break;
    }
    return (false);
}

bool cw__fetch_read_sparam(const cw_vm_t *vm, cw_param_type_t type,
    usize_t *addr, cw_param_t *param)
{
    param->type = type;
    switch (type) {
    case CW_PARAM_REG:
        param->u.reg = vm->mem[*addr % vm->config.mem_size] - 1;
        (*addr)++;
        if (param->u.reg >= vm->config.reg_count)
            return (true);
        break;
    case CW_PARAM_DIR:
        param->u.val = cw_vm__read_int(vm, *addr, vm->config.ind_size);
        *addr += vm->config.ind_size;
        break;
    case CW_PARAM_IND:
        param->u.val = cw_vm__read_int(vm, *addr, vm->config.ind_size);
        *addr += vm->config.ind_size;
        break;
    }
    return (false);
}
