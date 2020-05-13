/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Instruction data types
*/

#ifndef COREWAR_INSTR_H
#define COREWAR_INSTR_H

#include "my/types.h"

typedef enum {
    CW_INSTR_LIVE = 0x01,
    CW_INSTR_LD = 0x02,
    CW_INSTR_ST = 0x03,
    CW_INSTR_ADD = 0x04,
    CW_INSTR_SUB = 0x05,
    CW_INSTR_AND = 0x06,
    CW_INSTR_OR = 0x07,
    CW_INSTR_XOR = 0x08,
    CW_INSTR_ZJMP = 0x09,
    CW_INSTR_LDI = 0x0a,
    CW_INSTR_STI = 0x0b,
    CW_INSTR_FORK = 0x0c,
    CW_INSTR_LLD = 0x0d,
    CW_INSTR_LLDI = 0x0e,
    CW_INSTR_LFORK = 0x0f,
    CW_INSTR_AFF = 0x10,
} cw_opcode_t;

OPT_DEFINE(cw_opcode_t, cw_opcode)

#define CW_OPCODE_LAST CW_INSTR_AFF

/*
** Instruction parameters
*/

typedef enum {
    CW_PARAM_REG = 0,
    CW_PARAM_DIR = 1,
    CW_PARAM_IND = 2,
} cw_param_type_t;

typedef struct {
    cw_param_type_t type;
    union {
        u64_t val;
        u8_t reg;
    } u;
} cw_param_t;

/*
** Instruction
*/

typedef struct {
    cw_opcode_t opcode;
    cw_param_t args[4];
    usize_t end;
} cw_instr_t;

#endif /* COREWAR_INSTR_H */
