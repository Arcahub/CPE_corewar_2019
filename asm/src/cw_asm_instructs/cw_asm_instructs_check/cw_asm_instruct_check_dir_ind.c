/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"
#include "asm/instructs/cw_asm_instruct_check.h"

static char IND_DIR[2] = {T_IND, T_DIR};

char cw_asm_instruct_check_dir_ind(cw_asm_error_context_t err_context,
    char *parameter)
{
    bool direct = (parameter[0] == DIRECT_CHAR);

    if (parameter[direct] == LABEL_CHAR)
        return (cw_asm_instruct_check_label(&(parameter[direct + 1]))
            * IND_DIR[direct]);
    return (cw_asm_instruct_check_value(err_context, &(parameter[direct]))
        * IND_DIR[direct]);
}