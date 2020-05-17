/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** st
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw__fetch_st(const cw_vm_t *vm, const cw_core_t *core, cw_instr_t *instr)
{
    usize_t addr = core->regs.pc + 1;
    cw_pcb_t pcb;
    bool err = false;

    if (cw__pcb_parse(&pcb, vm->mem[cw_vm_compute_addr(vm, addr++)]) ||
        !cw__pcb_matches(&pcb, "r,ri"))
        return (true);
    err |= cw__fetch_read_param(vm, pcb.p[0], &addr, &instr->args[0]);
    err |= cw__fetch_read_param(vm, pcb.p[1], &addr, &instr->args[1]);
    instr->end = addr;
    return (err);
}
