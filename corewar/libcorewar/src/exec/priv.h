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
#include "../priv.h"

extern const u64_t CW__REG_MASK[8];
typedef void (exec_instr_fn_t)(cw_vm_t*, cw_core_t*, const cw_instr_t*);

u64_t cw_vm__exec_pget(const cw_core_t *core, const cw_param_t *param);
u64_t cw_vm__exec_plval(const cw_vm_t *vm, const cw_core_t *core,
    const cw_param_t *param, usize_t size);
u64_t cw_vm__exec_pval(const cw_vm_t *vm, const cw_core_t *core,
    const cw_param_t *param, usize_t size);

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

static inline i64_t reg_mask(const cw_vm_t *vm, i64_t val)
{
    u64_t abs = val > 0 ? val : -val;

    abs &= CW__REG_MASK[vm->config.reg_size];
    return (val > 0 ? (i64_t) abs : -((i64_t) abs));
}

#endif /* LIBCOREWAR_EXEC_PRIV */
