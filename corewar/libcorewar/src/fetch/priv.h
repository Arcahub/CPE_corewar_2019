/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** priv
*/

#ifndef FETCH_PRIV_H_
#define FETCH_PRIV_H_

#include "my/types.h"
#include "corewar/corewar.h"

typedef bool (*cw_fetch_fn_t)(cw_vm_t *vm, cw_core_t *current_core,
        cw_instr_t *instr);
extern const cw_fetch_fn_t FETCH_FUNCTIONS[256];

bool cw_fetch_add(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_aff(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_and(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_fork(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_ld(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_ldi(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_lfork(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_live(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_lld(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_lldi(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_or(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_st(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_sti(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_sub(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_xor(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_zjmp(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);
bool cw_fetch_fallback(cw_vm_t *vm, cw_core_t *current_core, cw_instr_t *instr);

bool cw_fetch_utils_populate_rvalue(cw_vm_t *vm, cw_core_t *current_core,
    cw_rvalue_t *r_value);

#endif /* !PRIV_H_ */
