/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Private header file used by the implementation
*/

#ifndef LIBCOREWAR_PRIV_H
#define LIBCOREWAR_PRIV_H

#include "corewar/corewar.h"
#include "corewar/instr.h"

bool cw_instruction_fetch(const cw_vm_t *vm, const cw_core_t *core,
    cw_instr_t *ret_instr);
bool cw_vm__trigger_callbacks(cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr);

bool cw_vm_add_core(cw_vm_t *vm, const usize_t pc, u32_t prog_number);
void cw_vm_destroy_core(cw_core_t *core);

#endif /* LIBCOREWAR_PRIV_H */
