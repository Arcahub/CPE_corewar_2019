/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_write
*/

#ifndef CW_ASM_INSTRUCT_CHECK_H_
#define CW_ASM_INSTRUCT_CHECK_H_

#include "instructs/cw_asm_instruct.h"
#include "error/cw_asm_error.h"

int cw_asm_instruct_check_value(cw_asm_error_context_t context,
    char *parameter);
int cw_asm_instruct_check_reg(char *parameter);
int cw_asm_instruct_check_label(char *parameter);
char cw_asm_instruct_check_dir_ind(cw_asm_error_context_t err_context,
    char *parameter);

#endif /* !CW_ASM_INSTRUCT_CHECK_H_ */
