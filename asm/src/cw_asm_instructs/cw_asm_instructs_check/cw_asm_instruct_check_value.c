/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"
#include "asm/error/cw_asm_error.h"

static int is_only_numeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return (0);
    }
    return (1);
}

int cw_asm_instruct_check_value(cw_asm_error_context_t context,
    char *parameter)
{
    bool test = is_only_numeric(parameter);

    if (!test) {
        cw_asm_error_list((cw_asm_error_context_t){context.line,
            context.column, ERROR, context.str_line},
            "%s is not a number", parameter);
    }
    return (test);
}