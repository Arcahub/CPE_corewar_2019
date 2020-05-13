/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Private header file used by the instruction executor
*/

#ifndef LIBCOREWAR_EXEC_PRIV
#define LIBCOREWAR_EXEC_PRIV

#include "corewar/corewar.h"
#include "corewar/instr.h"

typedef void (exec_instr_fn_t)(cw_vm_t*, cw_core_t*, const cw_instr_t*);

exec_instr_fn_t cw_vm__exec__add;
exec_instr_fn_t cw_vm__exec__aff;
exec_instr_fn_t cw_vm__exec__and;
exec_instr_fn_t cw_vm__exec__fork;
exec_instr_fn_t cw_vm__exec__ld;
exec_instr_fn_t cw_vm__exec__ldi;
exec_instr_fn_t cw_vm__exec__lfork;
exec_instr_fn_t cw_vm__exec__live;
exec_instr_fn_t cw_vm__exec__lld;
exec_instr_fn_t cw_vm__exec__lldi;
exec_instr_fn_t cw_vm__exec__or;
exec_instr_fn_t cw_vm__exec__st;
exec_instr_fn_t cw_vm__exec__sti;
exec_instr_fn_t cw_vm__exec__sub;
exec_instr_fn_t cw_vm__exec__xor;
exec_instr_fn_t cw_vm__exec__zjmp;

#endif /* LIBCOREWAR_EXEC_PRIV */
