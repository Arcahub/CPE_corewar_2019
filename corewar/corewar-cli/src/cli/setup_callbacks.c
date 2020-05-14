/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** setup_callbacks
*/

#include "corewar/corewar.h"
#include "my/my.h"

static const char *OPCODE_NAMES[] = {
    NULL,
    "live",
    "ld",
    "st",
    "add",
    "sub",
    "and",
    "or",
    "xor",
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lld",
    "lldi",
    "lfork",
    "aff",
};

bool print_instruct(void *user_data, cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t*instr)
{
    my_printf("opcode: %s, pc: %x\n", OPCODE_NAMES[instr->opcode],
    core->regs.pc);
}

void cw_corewar_cli_setup_callbacks(cw_vm_t *vm)
{
    cw_vm_add_instr_callback(vm, NONE(cw_opcode), &print_instruct, NULL);
}
