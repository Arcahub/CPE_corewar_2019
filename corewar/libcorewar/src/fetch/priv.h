/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** priv
*/

#ifndef FETCH_PRIV_H_
#define FETCH_PRIV_H_

#include "my/types.h"
#include "corewar/corewar.h"
#include "corewar/instr.h"
#include "../priv.h"

typedef struct {
    u8_t raw;
    usize_t count;
    cw_param_type_t p[4];
} cw_pcb_t;

typedef bool (cw__fetch_fn_t)(const cw_vm_t *vm, const cw_core_t *core,
    cw_instr_t *instr);
extern cw__fetch_fn_t *const FETCH_FUNCTIONS[256];

bool cw__pcb_parse(cw_pcb_t *pcb, u8_t raw);
bool cw__pcb_matches(const cw_pcb_t *pcb, const char *str);
cw__fetch_fn_t cw__fetch_add;
cw__fetch_fn_t cw__fetch_aff;
cw__fetch_fn_t cw__fetch_and;
cw__fetch_fn_t cw__fetch_fork;
cw__fetch_fn_t cw__fetch_ld;
cw__fetch_fn_t cw__fetch_ldi;
cw__fetch_fn_t cw__fetch_lfork;
cw__fetch_fn_t cw__fetch_live;
cw__fetch_fn_t cw__fetch_lld;
cw__fetch_fn_t cw__fetch_lldi;
cw__fetch_fn_t cw__fetch_or;
cw__fetch_fn_t cw__fetch_st;
cw__fetch_fn_t cw__fetch_sti;
cw__fetch_fn_t cw__fetch_sub;
cw__fetch_fn_t cw__fetch_xor;
cw__fetch_fn_t cw__fetch_zjmp;

bool cw__fetch_read_param(const cw_vm_t *vm, cw_param_type_t type,
    usize_t *addr, cw_param_t *param);
bool cw__fetch_read_sparam(const cw_vm_t *vm, cw_param_type_t type,
    usize_t *addr, cw_param_t *param);

#endif /* !PRIV_H_ */
