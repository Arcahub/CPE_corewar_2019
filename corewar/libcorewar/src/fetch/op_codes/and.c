/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** and
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw_fetch_and(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    // u8_t coding = vm->mem[current_core->regs.pc++ % vm->config.mem_size];

    // instr->args.and.a.type = coding & 0xC0;
    // instr->args.and.b.type = coding & 0x30;
    // if (cw_fetch_utils_populate_param(vm, current_core, &instr->args.and.a))
    //     return (true);
    // if (cw_fetch_utils_populate_param(vm, current_core, &instr->args.and.b))
    //     return (true);
    // instr->args.and.dst =
    //     vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    (void)(vm);
    (void)(current_core);
    (void)(instr);
    return (false);
}
