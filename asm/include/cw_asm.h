/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm
*/

#ifndef CW_ASM_H_
#define CW_ASM_H_

#include "my/my.h"
#include "my/io.h"
#include "asm/op.h"

typedef struct header_s cw_asm_header_t;
typedef struct cw_asm_instruct_s cw_asm_instruct_t;

typedef struct {
    void *data;
    usize_t len;
} cw_asm_output_buff_t;

typedef struct cw_asm_s {
    cw_asm_header_t *header;
    cw_asm_instruct_t *instructs;
    int fdout;
    bufreader_t *fdin;
} cw_asm_t;

int cw_asm(int, char **);
cw_asm_t *cw_asm_create(char *path);
void cw_asm_destroy(cw_asm_t *self);
int cw_asm_output_create(char *);
bufreader_t *cw_asm_input_open(char *path);
void cw_asm_write(cw_asm_t *self);
void cw_asm_get_prog_size(cw_asm_t *self);
bool cw_asm_is_line_useless(char *line);

#endif /* !CW_ASM_H_ */