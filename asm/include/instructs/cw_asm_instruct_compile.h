/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_compile
*/

#ifndef CW_ASM_INSTRUCT_COMPILE_H_
#define CW_ASM_INSTRUCT_COMPILE_H_

#include "instructs/cw_asm_instruct.h"

void cw_asm_instruct_compile_global(cw_asm_instruct_t *instruct);
void cw_asm_instruct_compile_live(cw_asm_instruct_t *instruct);
void cw_asm_instruct_compile_sti_ldi(cw_asm_instruct_t *instruct);
void cw_asm_instruct_compile_zjump(cw_asm_instruct_t *instruct);
void cw_asm_instruct_compile_fork(cw_asm_instruct_t *instruct);
void cw_asm_instruct_compile_lfork(cw_asm_instruct_t *instruct);
void cw_asm_instruct_compile_lldii(cw_asm_instruct_t *instruct);

static void (*CW_ASM_INSTRUCTS_COMPILE_FP[])(cw_asm_instruct_t *) = {
    &cw_asm_instruct_compile_live,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_zjump,
    &cw_asm_instruct_compile_sti_ldi,
    &cw_asm_instruct_compile_sti_ldi,
    &cw_asm_instruct_compile_fork,
    &cw_asm_instruct_compile_global,
    &cw_asm_instruct_compile_lldii,
    &cw_asm_instruct_compile_lfork,
    &cw_asm_instruct_compile_global,
};
#endif /* !CW_ASM_INSTRUCT_COMPILE_H_ */
