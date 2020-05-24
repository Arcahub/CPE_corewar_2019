/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"

static int is_only_numeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int cw_asm_instruct_check_reg(cw_asm_error_context_t context,
    char *parameter)
{
    int nb = 0;

    if (parameter[0] != 'r')
        return (0);
    nb = my_getnbr(&(parameter[1]));
    if (!is_only_numeric(&(parameter[1]))
        || nb < 1 || nb > REG_NUMBER) {
        cw_asm_error_list(cw_asm_error_context_change_type(context, ERROR),
            "%s is not a valid register.\n"\
            "    You can use the registers from r1 to r%d", parameter,
            REG_NUMBER);
        return (2);
    }
    return (1);
}
