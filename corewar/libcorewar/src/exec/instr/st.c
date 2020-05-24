/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** "st" instruction implementation
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

void cw_vm__exec__st(cw_vm_t *vm, cw_core_t *core, const cw_instr_t *instr)
{
    i64_t val = cw_vm__exec_pget(core, &instr->args[0]);

    switch (instr->args[1].type) {
    case CW_PARAM_IND:
        cw_vm__write_int(vm, val, core->regs.pc + instr->args[1].u.val,
            vm->config.reg_size, core);
        break;
    case CW_PARAM_REG:
        core->regs.regs[instr->args[1].u.reg] = val;
        break;
    default:
        break;
    }
    core->regs.pc = instr->end;
}
