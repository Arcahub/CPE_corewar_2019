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
#include "my/my.h"

u64_t cw_vm__exec_pget(const cw_core_t *core, const cw_param_t *param)
{
    switch (param->type) {
    case CW_PARAM_REG:
        return (core->regs.regs[param->u.reg]);
    case CW_PARAM_IND:
    case CW_PARAM_DIR:
        return (param->u.val);
    }
    return (0);
}

u64_t cw_vm__exec_plval(const cw_vm_t *vm, const cw_core_t *core,
    const cw_param_t *param, usize_t size)
{
    switch (param->type) {
    case CW_PARAM_REG:
        return (core->regs.regs[param->u.reg]);
    case CW_PARAM_IND:
        return (cw_vm__read_int(vm, core->regs.pc + param->u.val, size));
    case CW_PARAM_DIR:
        return (param->u.val);
    }
    return (0);
}

u64_t cw_vm__exec_pval(const cw_vm_t *vm, const cw_core_t *core,
    const cw_param_t *param, usize_t size)
{
    switch (param->type) {
    case CW_PARAM_REG:
        return (core->regs.regs[param->u.reg]);
    case CW_PARAM_IND:
        return (cw_vm__read_int(vm,
            core->regs.pc + param->u.val % vm->config.idx_mod, size));
    case CW_PARAM_DIR:
        return (param->u.val);
    }
    return (0);
}
