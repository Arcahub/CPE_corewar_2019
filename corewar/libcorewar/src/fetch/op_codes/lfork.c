/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** lfork
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_lfork(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    // instr->args.lfork.addr =
    //     &vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    (void)(vm);
    (void)(current_core);
    (void)(instr);
    return (false);
}
