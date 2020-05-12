/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** libcorewar's API public header file
*/

#ifndef LIBCOREWAR_H
#define LIBCOREWAR_H

#include "my/types.h"
#include "my/collections/vec.h"
#include "my/collections/list.h"
#include "corewar/instr.h"

typedef struct {
    usize_t prog_name_length;
    usize_t comment_length;
    u32_t corewar_exec_magic;
    usize_t reg_size;
    usize_t idx_mod;
    usize_t ind_size;
    usize_t dir_size;
    usize_t mem_size;
    u64_t cycle_to_die;
    u64_t cycle_delta;
    u64_t nbr_live;
} cw_config_t;

typedef struct {
    OPT(u32) prog_number;
    OPT(usize) load_address;
    u8_t *data;
    usize_t size;
} cw_program_def_t;

typedef struct {
    char *name;
    char *comment;
    const u32_t prog_number;
} cw_program_t;

typedef struct {
    struct {
        usize_t pc;
        u8_t **regs;
        bool zero;
    } regs;
    struct {
        usize_t timeout;
        u64_t age;
    } state;
    struct {
        OPT(cw_instr) instruct;
    } cache;
} cw_core_t;

typedef struct cw_vm cw_vm_t;

typedef struct {
    bool (*fn)(void*, cw_vm_t*, cw_core_t *core, const cw_instr_t*);
    void *data;
} cw_instr_callback_t;

struct cw_vm {
    const cw_config_t config;
    u64_t cycle_to_die;
    u8_t *mem;
    usize_t prog_count;
    cw_program_t *programs;
    vec_t *cores;
    struct {
        list_t *all;
        list_t *opcodes[CW_OPCODE_LAST + 1];
    } callbacks;
};

/*
** Creating and destroying the VM
*/

cw_vm_t *cw_vm_new(const cw_config_t *config, const cw_program_def_t *defs,
    usize_t prog_count);
void cw_vm_destroy(cw_vm_t *self);

/*
** Running the VM
*/

bool cw_vm_run(cw_vm_t *self, OPT(u64) cycle_count);

/*
** Callbacks
*/

void cw_vm_add_instr_callback(cw_vm_t *self, OPT(cw_opcode) opcode_filter,
    bool (*fn)(void*, cw_vm_t*, cw_core_t *core, const cw_instr_t*), void*);
void *cw_vm_remove_instr_callback(cw_vm_t *self, OPT(cw_opcode) opcode_filter,
    bool (*fn)(void*, cw_vm_t*, cw_core_t *core, const cw_instr_t*));

/*
** Utilities
*/

OPT(u64) cw_vm_get_age(const cw_vm_t *self, usize_t load_id);
usize_t cw_vm_memory_dump(const cw_vm_t *self, u8_t *buf, usize_t count);

#endif /* LIBCOREWAR_H */
