/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** live
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_live(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    my_memcpy(&(instr->args.live.nb), &(vm->mem[current_core->regs.pc++]),
        sizeof(u32_t));
    instr->args.live.nb = u32_be_to_ne(instr->args.live.nb);
    return (false);
}
