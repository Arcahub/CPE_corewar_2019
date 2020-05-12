/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** zjmp
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_zjmp(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    instr->args.zjmp.addr =
        &vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    return (false);
}
