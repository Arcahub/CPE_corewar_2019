/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct
*/

#ifndef CW_ASM_INSTRUCT_H_
#define CW_ASM_INSTRUCT_H_

#include "op.h"

typedef struct cw_asm_instruct_s {
    char *label;
    unsigned int instruct_code;
    char *parameters[MAX_ARGS_NUMBER];
    char coding_byte;
    struct cw_asm_instruct_s *next;
} cw_asm_instruct_t;

void cw_asm_instruct_destroy(cw_asm_instruct_t *self, cw_asm_instruct_t **list);
cw_asm_instruct_t *cw_asm_instruct_create(cw_asm_instruct_t *last);
int cw_asm_check_params(cw_asm_instruct_t *instruct);

#endif /* !CW_ASM_INSTRUCT_H_ */
