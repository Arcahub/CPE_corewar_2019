/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** ldi
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"

bool cw__fetch_ldi(const cw_vm_t *vm, const cw_core_t *core, cw_instr_t *instr)
{
    usize_t addr = core->regs.pc + 1;
    cw_pcb_t pcb;

    if (cw__pcb_parse(&pcb, vm->mem[addr++]) ||
        cw__pcb_matches(&pcb, "rdi,rd,r"))
        return (true);
    pcb.p[0] = pcb.p[0] == CW_PARAM_DIR ? CW_PARAM_IND : pcb.p[0];
    pcb.p[1] = pcb.p[1] == CW_PARAM_DIR ? CW_PARAM_IND : pcb.p[1];
    instr->args[0] = cw__fetch_read_param(vm, core, pcb.p[0], &addr);
    instr->args[1] = cw__fetch_read_param(vm, core, pcb.p[1], &addr);
    instr->end = addr;
    return (false);
}
