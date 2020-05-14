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
