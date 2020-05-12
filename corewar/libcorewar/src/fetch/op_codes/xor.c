/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** xor
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw_fetch_xor(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr)
{
    u8_t coding = vm->mem[current_core->regs.pc++ % vm->config.mem_size];

    instr->args.xor.a.type = u8_be_to_ne(coding & 0xC0);
    instr->args.xor.b.type = u8_be_to_ne(coding & 0x30);
    if (cw_fetch_utils_populate_rvalue(vm, current_core, &instr->args.xor.a))
        return (true);
    if (cw_fetch_utils_populate_rvalue(vm, current_core, &instr->args.xor.b))
        return (true);
    instr->args.xor.dst =
        vm->mem[current_core->regs.pc++ % vm->config.mem_size];
    return (false);
}
