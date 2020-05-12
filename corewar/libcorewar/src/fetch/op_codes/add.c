/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** add
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw_fetch_add(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    if (cw_pcb_matches(vm->mem[current_core->regs.pc], "r,r,r"))
        return (true);
    current_core->regs.pc++;
    instr->args.add.a.type = CW_PARAM_REG;
    instr->args.add.a.u.reg = vm->mem[current_core->regs.pc++];
    instr->args.add.b.type = CW_PARAM_REG;
    instr->args.add.b.u.reg = vm->mem[current_core->regs.pc++];
    instr->args.add.dst.type = CW_PARAM_REG;
    instr->args.add.dst.u.reg = vm->mem[current_core->regs.pc++];
    return (false);
}
