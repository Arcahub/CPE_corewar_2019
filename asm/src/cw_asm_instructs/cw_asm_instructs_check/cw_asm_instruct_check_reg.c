/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"
#include "asm/my.h"

static int is_only_numeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int cw_asm_instruct_check_reg(char *parameter)
{
    int nb = 0;

    if (parameter[0] != 'r')
        return (0);
    nb = my_getnbr(&(parameter[1]));
    if (!is_only_numeric(&(parameter[1]))
        || nb < 1 || nb > REG_NUMBER)
        return (2);
    return (1);
}