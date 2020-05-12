/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** add
*/

#include "my/my.h"
#include "corewar/corewar.h"

/*
** Line 16, Consume the (cmchalice) useless coding byte
*/
bool cw_fetch_add(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    current_core->regs.pc++;
    instr->args.add.a = vm->mem[current_core->regs.pc++];
    instr->args.add.b = vm->mem[current_core->regs.pc++];
    instr->args.add.dst = vm->mem[current_core->regs.pc++];
    return (false);
}
