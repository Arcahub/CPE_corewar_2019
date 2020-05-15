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

static u64_t read_int(const cw_vm_t *vm, usize_t *addr, usize_t n)
{
    union {
        u64_t u64;
        u8_t bytes[8];
    } val = {0};

    for (usize_t i = 0; i < n; i++)
        val.bytes[i] = vm->mem[(*addr + i) % vm->config.mem_size];
    *addr += n;
    return (u64_be_to_ne(val.u64));
}

cw_param_t cw__fetch_read_int(const cw_vm_t *vm, usize_t size, usize_t *addr)
{
    cw_param_t param;

    param.type = CW_PARAM_DIR;
    param.u.val = read_int(vm, addr, size);
    return (param);
}

bool cw__fetch_read_param(const cw_vm_t *vm, cw_param_type_t type,
    usize_t *addr, cw_param_t *param)
{
    param->type = type;
    switch (type) {
    case CW_PARAM_REG:
        param->u.reg = vm->mem[*addr % vm->config.mem_size];
        (*addr)++;
        if (param->u.reg < 1 && param->u.reg > vm->config.reg_count)
            return (true);
        break;
    case CW_PARAM_DIR:
        param->u.val = read_int(vm, addr, vm->config.dir_size);
        break;
    case CW_PARAM_IND:
        param->u.val = read_int(vm, addr, vm->config.ind_size);
        break;
    }
    return (false);
}
