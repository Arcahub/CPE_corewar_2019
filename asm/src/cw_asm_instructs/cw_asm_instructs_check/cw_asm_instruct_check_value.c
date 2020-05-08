/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "cw_asm.h"
#include "instructs/cw_asm_instruct.h"

static int is_only_numeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int cw_asm_instruct_check_value(char *parameter)
{
    return is_only_numeric(parameter);
}