/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** xor
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw__fetch_xor(const cw_vm_t *vm, const cw_core_t *core, cw_instr_t *instr)
{
    usize_t addr = core->regs.pc + 1;
    cw_pcb_t pcb;

    if (cw__pcb_parse(&pcb, vm->mem[addr++]) ||
        cw__pcb_matches(&pcb, "rdi,rdi,r"))
        return (true);
    instr->args[0] = cw__fetch_read_param(vm, pcb.p[0], &addr);
    instr->args[1] = cw__fetch_read_param(vm, pcb.p[1], &addr);
    instr->args[2] = cw__fetch_read_param(vm, pcb.p[2], &addr);
    instr->end = addr;
    return (false);
}
