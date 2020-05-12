/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** aff
*/

#include "my/my.h"
#include "corewar/corewar.h"

/*
** Line 16: Consume the (cmchalice) useless coding byte
*/
bool cw_fetch_aff(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    current_core->regs.pc++;
    instr->args.aff.reg =
        vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    return (false);
}
