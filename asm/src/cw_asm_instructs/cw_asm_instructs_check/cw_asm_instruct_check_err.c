/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"
#include "asm/instructs/cw_asm_instruct_check.h"

void cw_asm_instruct_check_args_type_err(char *parameter,
    cw_asm_error_context_t err_context, args_type_t valid, args_type_t type)
{
    char *str_type = "";
    char *str_valid[3] = {"", "", ""};

    str_valid[0] = ((valid | T_DIR) == valid) ? " direct" : "";
    str_valid[1] = ((valid | T_IND) == valid) ? " indirect" : "";
    str_valid[2] = ((valid | T_REG) == valid) ? " register" : "";
    str_type = (type == T_DIR) ? "a direct" : str_type;
    str_type = (type == T_IND) ? "an indirect" : str_type;
    str_type = (type == T_REG) ? "a register" : str_type;
    cw_asm_error_list(cw_asm_error_context_change_type(err_context, ERROR),
        "%s is %s which is not a valid type.\n"\
        "    Allowed types are :%s%s%s", parameter, str_type, str_valid[0],
        str_valid[1], str_valid[2]);
}