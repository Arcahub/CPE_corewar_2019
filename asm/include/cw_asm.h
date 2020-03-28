/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm
*/

#ifndef CW_ASM_H_
#define CW_ASM_H_

#include <stdbool.h>
#include <stdio.h>
#include "op.h"

typedef struct instruct_s {
    char *label;
    unsigned int instruct_code;
    char *parameters[MAX_ARGS_NUMBER];
    char coding_byte;
    struct instruct_s *next;
} instruct_t;

int cw_asm(int, char **);
int cw_asm_compile(FILE *, int);
int cw_asm_compile_header(FILE *, header_t *);
int cw_asm_format_instructs(instruct_t **, FILE *);
int cw_asm_create_output(char *);
bool cw_asm_check_file(char *, FILE **);
int cw_asm_write_header(int, header_t *);
void cw_asm_free_instructs_list(instruct_t *);
int cw_asm_check_params(instruct_t *);
int cw_asm_get_prog_size(instruct_t *);

#endif /* !CW_ASM_H_ */
