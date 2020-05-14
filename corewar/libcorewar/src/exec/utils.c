/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Utilities used by instructions
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "priv.h"

u64_t cw_vm__exec__pval(const cw_core_t *core, const cw_param_t *param)
{
    switch (param->type) {
    case CW_PARAM_REG:
        return (core->regs.regs[param->u.reg]);
    case CW_PARAM_IND:
    case CW_PARAM_DIR:
        return (param->u.val);
    }
}

u64_t cw_vm__exec_pval(const cw_vm_t *vm, const cw_core_t *core,
    const cw_param_t *param, usize_t size)
{
    union {
        u64_t u64;
        u8_t bytes[8];
    } val = {0};

    switch (param->type) {
    case CW_PARAM_REG:
        return (core->regs.regs[param->u.reg]);
    case CW_PARAM_IND:
        size = usize_min(size, 8);
        for (usize_t i = core->regs.pc; i < core->regs.pc + size; i++)
            val.bytes[i] = vm->mem[(param->u.val + i) % vm->config.mem_size];
        return (val.u64);
    case CW_PARAM_DIR:
        return (param->u.val);
    }
}
