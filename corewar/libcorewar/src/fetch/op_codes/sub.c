/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** sub
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_sub(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    // current_core->regs.pc++;
    // instr->args.sub.a = vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    // instr->args.sub.b = vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    // instr->args.sub.dst =
    //     vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    (void)(vm);
    (void)(current_core);
    (void)(instr);
    return (false);
}
