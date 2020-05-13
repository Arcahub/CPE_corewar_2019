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

typedef u8_t cw_val_reg_t;
typedef u8_t *cw_val_dir_t;
typedef u8_t *cw_val_ind_t;

/*
** Right-values (readables)
*/

typedef enum {
    CW_RVAL_REG = 1,
    CW_RVAL_DIR = 2,
    CW_RVAL_IND = 4,
} cw_rval_type_t;

typedef struct {
    cw_rval_type_t type;
    union {
        cw_val_reg_t reg;
        cw_val_dir_t dir;
        cw_val_ind_t ind;
    } u;
} cw_rvalue_t;

/*
** Left-values (writeables)
*/

typedef enum {
    CW_LVAL_REG = CW_RVAL_REG,
    CW_LVAL_IND = CW_RVAL_IND,
} cw_lval_type_t;

typedef struct {
    cw_lval_type_t type;
    union {
        cw_val_reg_t reg;
        cw_val_ind_t ind;
    } u;
} cw_lvalue_t;

/*
** Index values (can't be indirect for some reason)
*/

typedef enum {
    CW_IVAL_REG = CW_RVAL_REG,
    CW_IVAL_DIR = CW_RVAL_DIR,
} cw_ival_type_t;

typedef struct {
    cw_ival_type_t type;
    union {
        cw_val_reg_t reg;
        cw_val_dir_t dir;
    } u;
} cw_ivalue_t;

/*
** Instruction
*/

typedef struct {
    cw_opcode_t opcode;
    union {
        struct {
            u32_t nb;
        } live;
        struct {
            cw_lvalue_t src;
            cw_val_reg_t dst;
        } ld;
        struct {
            cw_val_reg_t src;
            cw_lvalue_t dst;
        } st;
        struct {
            cw_val_reg_t a;
            cw_val_reg_t b;
            cw_val_reg_t dst;
        } add;
        struct {
            cw_val_reg_t a;
            cw_val_reg_t b;
            cw_val_reg_t dst;
        } sub;
        struct {
            cw_rvalue_t a;
            cw_rvalue_t b;
            cw_val_reg_t dst;
        } and;
        struct {
            cw_rvalue_t a;
            cw_rvalue_t b;
            cw_val_reg_t dst;
        } or;
        struct {
            cw_rvalue_t a;
            cw_rvalue_t b;
            cw_val_reg_t dst;
        } xor;
        struct {
            cw_val_ind_t addr;
        } zjmp;
        struct {
            cw_rval_type_t base;
            cw_ival_type_t ind;
            cw_val_reg_t dst;
        } ldi;
        struct {
            cw_val_reg_t src;
            cw_rval_type_t base;
            cw_ival_type_t ind;
        } sti;
        struct {
            cw_val_ind_t addr;
        } fork;
        struct {
            cw_lvalue_t src;
            cw_val_reg_t dst;
        } lld;
        struct {
            cw_rval_type_t base;
            cw_ival_type_t ind;
            cw_val_reg_t dst;
        } lldi;
        struct {
            cw_val_ind_t addr;
        } lfork;
        struct {
            cw_val_reg_t reg;
        } aff;
    } args;
} cw_instr_t;

OPT_DEFINE(cw_instr_t, cw_instr)

#endif /* COREWAR_INSTR_H */
