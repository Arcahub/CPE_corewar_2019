/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct
*/

#ifndef CW_ASM_INSTRUCT_H_
#define CW_ASM_INSTRUCT_H_

#include "asm/error/cw_asm_error.h"
#include "asm/op.h"
#include "my/io.h"

typedef struct cw_asm_instruct_s {
    char *label;
    char instruct_code;
    char *parameters[MAX_ARGS_NUMBER];
    char coding_byte;
    int instruct_size;
    struct cw_asm_instruct_s *next;
    struct cw_asm_instruct_s *last;
} cw_asm_instruct_t;

void cw_asm_instruct_destroy(cw_asm_instruct_t *self, cw_asm_instruct_t **list);
cw_asm_instruct_t *cw_asm_instruct_create(cw_asm_instruct_t *last);
int cw_asm_check_params(cw_asm_instruct_t *instruct);
int cw_asm_instruct_load(cw_asm_instruct_t **instructs_list, bufreader_t *fdin);
void cw_asm_instruct_write_args(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **instructs_list, int *offset, bufwriter_t *bw);
void cw_asm_instruct_load_args(cw_asm_error_context_t err_context,
    cw_asm_instruct_t *instruct, char **line);
void cw_asm_instruct_load_cmd(cw_asm_instruct_t *instruct, char **line);
void cw_asm_instruct_load_label(cw_asm_instruct_t *instruct, char **line);
void cw_asm_instructs_compile(cw_asm_instruct_t *instructs_list);
void cw_asm_instructs_write(cw_asm_instruct_t *instructs_list, bufwriter_t *bw);
int cw_asm_instruct_check_args(cw_asm_error_context_t err_context,
    cw_asm_instruct_t *instruct);
int cw_asm_instruct_write_arg_direct(cw_asm_instruct_t *instruct,
cw_asm_instruct_t *instructs_list,
int offset, int i);
int cw_asm_instruct_write_arg_indirect(char *arg,
    cw_asm_instruct_t *instructs_list, int offset);

#endif /* !CW_ASM_INSTRUCT_H_ */
