/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** fork
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_fork(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    instr->args.fork.addr =
        &vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    return (false);
}
