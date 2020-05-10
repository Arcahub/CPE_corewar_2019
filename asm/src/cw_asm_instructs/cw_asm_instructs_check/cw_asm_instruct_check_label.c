/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"

static int cw_asm_instruct_check_label_char(char c)
{
    for (int i = 0; LABEL_CHARS[i]; i++)
        if (c == LABEL_CHARS[i])
            return (0);
    return (1);
}

int cw_asm_instruct_check_label(char *parameter)
{
    for (int i = 0; parameter[i]; i++) {
        if (cw_asm_instruct_check_label_char(parameter[i]))
            return (0);
    }
    return (1);
}