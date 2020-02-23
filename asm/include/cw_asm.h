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

int cw_asm(int, char **);
int cw_asm_compile(FILE *, int);
int cw_asm_compile_header(FILE *, int, header_t *);
int cw_asm_create_output(char *);
bool cw_asm_check_file(char *, FILE **);
int write_header(int, header_t *);

#endif /* !CW_ASM_H_ */
