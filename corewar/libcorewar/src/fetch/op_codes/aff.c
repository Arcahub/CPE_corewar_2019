/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** aff
*/

#include "my/my.h"
#include "corewar/corewar.h"

bool cw_fetch_aff(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    // u8_t pcb = vm->mem[current_core->regs.pc++];

    // if (pcb != 0x40)
    //     return (true);
    // current_core->regs.pc++;
    // instr->args.aff.reg.type = CW_PARAM_REG;
    // instr->args.aff.reg.u.reg =
    //     vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    (void)(vm);
    (void)(current_core);
    (void)(instr);
    return (false);
}
