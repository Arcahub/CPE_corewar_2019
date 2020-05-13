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
void cw_vm__exec_instr(cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr);

#endif /* LIBCOREWAR_PRIV_H */
