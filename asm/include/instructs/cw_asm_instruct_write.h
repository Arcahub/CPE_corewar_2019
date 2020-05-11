/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_write
*/

#ifndef CW_ASM_INSTRUCT_WRITE_H_
#define CW_ASM_INSTRUCT_WRITE_H_

#include "asm/instructs/cw_asm_instruct.h"

void cw_asm_instruct_add_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_aff_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_and_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_fork_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_ld_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_ldi_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_lfork_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_live_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_lld_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_lldi_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_or_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_st_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_sti_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_sub_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_xor_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);
void cw_asm_instruct_zjump_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset);

static void (*CW_ASM_INSTRUCTS_WRITE_FP[])(cw_asm_instruct_t *,
cw_asm_instruct_t **,
bufwriter_t *bw, int *offset) = {
    &cw_asm_instruct_live_write,
    &cw_asm_instruct_ld_write,
    &cw_asm_instruct_st_write,
    &cw_asm_instruct_add_write,
    &cw_asm_instruct_sub_write,
    &cw_asm_instruct_and_write,
    &cw_asm_instruct_or_write,
    &cw_asm_instruct_xor_write,
    &cw_asm_instruct_zjump_write,
    &cw_asm_instruct_ldi_write,
    &cw_asm_instruct_sti_write,
    &cw_asm_instruct_fork_write,
    &cw_asm_instruct_lld_write,
    &cw_asm_instruct_lldi_write,
    &cw_asm_instruct_lfork_write,
    &cw_asm_instruct_aff_write,
};

#endif /* !CW_ASM_INSTRUCT_WRITE_H_ */
