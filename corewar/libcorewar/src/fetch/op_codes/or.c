/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** or
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw_fetch_or(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    u8_t coding = vm->mem[current_core->regs.pc++ % vm->config.mem_size];

    instr->args.or.a.type = u8_be_to_ne(coding & 0xC0);
    instr->args.or.b.type = u8_be_to_ne(coding & 0x30);
    if (cw_fetch_utils_populate_rvalue(vm, current_core, &instr->args.or.a))
        return (true);
    if (cw_fetch_utils_populate_rvalue(vm, current_core, &instr->args.or.b))
        return (true);
    instr->args.or.dst =
        vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    return (false);
}
