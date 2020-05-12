/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** lldi
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_lldi(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    // current_core->regs.pc++;

    // instr->args.lldi.dst = 
    //     vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    (void)(vm);
    (void)(current_core);
    (void)(instr);
    return (true);
}
