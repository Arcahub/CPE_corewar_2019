/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_write
*/

#ifndef CW_ASM_INSTRUCT_CHECK_H_
#define CW_ASM_INSTRUCT_CHECK_H_

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/error/cw_asm_error.h"

int cw_asm_instruct_check_value(cw_asm_error_context_t context,
    char *parameter);
int cw_asm_instruct_check_reg(cw_asm_error_context_t context, char *parameter);
int cw_asm_instruct_check_label(cw_asm_error_context_t err_context,
    char *parameter);
char cw_asm_instruct_check_dir_ind(cw_asm_error_context_t err_context,
    char *parameter);

//error output
void cw_asm_instruct_check_args_type_err(char *parameter,
    cw_asm_error_context_t err_context, args_type_t valid, args_type_t type);
void cw_asm_instruct_check_args_len_err(
    cw_asm_error_context_t err_context, op_t op, int i);

#endif /* !CW_ASM_INSTRUCT_CHECK_H_ */
