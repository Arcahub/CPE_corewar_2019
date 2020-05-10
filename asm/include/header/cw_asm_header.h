/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_header
*/

#ifndef CW_ASM_HEADER_H_
#define CW_ASM_HEADER_H_

#include "asm/op.h"
#include "my/io.h"

typedef struct header_s cw_asm_header_t;

cw_asm_header_t *cw_asm_header_create(void);
void cw_asm_header_destroy(cw_asm_header_t *self);

int cw_asm_header_write(cw_asm_header_t *self, int fdout);
int cw_asm_header_load(cw_asm_header_t *self, bufreader_t *fdin);

#endif /* !CW_ASM_HEADER_H_ */
