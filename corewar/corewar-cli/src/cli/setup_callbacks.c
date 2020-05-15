/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** setup_callbacks
*/

#include "corewar/corewar.h"
#include "my/my.h"
#include "my/io.h"

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

static const usize_t OPCODE_ARGS[] = {
    0, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1,
};

bool print_instruct(void *user_data, cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr)
{
    (void)(user_data);
    (void)(vm);
    my_printf("%.8x: %-5s ", core->regs.pc, OPCODE_NAMES[instr->opcode]);
    for (usize_t i = 0; i < OPCODE_ARGS[instr->opcode]; i++) {
        switch (instr->args[i].type) {
        case CW_PARAM_REG:
            my_printf("r%u", instr->args[i].u.reg + 1);
            break;
        case CW_PARAM_DIR:
            my_printf("%%%ld", (i64_t) instr->args[i].u.val);
            break;
        case CW_PARAM_IND:
            my_printf("%ld", (i64_t) instr->args[i].u.val);
            break;
        }
        my_putchar(i + 1 == OPCODE_ARGS[instr->opcode] ? '\n' : ',');
    }
    return (false);
}

void cw_corewar_cli_setup_callbacks(cw_vm_t *vm)
{
    cw_vm_add_instr_callback(vm, NONE(cw_opcode), &print_instruct, NULL);
}
