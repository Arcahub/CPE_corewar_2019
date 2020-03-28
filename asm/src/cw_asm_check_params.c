/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_check_params
*/

#include "cw_asm.h"

char cw_asm_get_arg_type(char *arg, char type)
{
    char c_type = 0;

    switch (arg[0]) {
        case 'r':
            c_type = T_REG;
            break;
        case DIRECT_CHAR:
            c_type = T_DIR;
            break;
        default:
            c_type = T_IND;
    }
    if (c_type & type)
        return (c_type);
    return (84);
}

int cw_asm_check_params(instruct_t *instruct)
{
    int i = 0;

    for (; instruct->parameters[i] && i < MAX_ARGS_NUMBER; i++);
    if (i != op_tab[instruct->instruct_code].nbr_args)
        return (84);
    for (i = 0; instruct->parameters[i] && i < MAX_ARGS_NUMBER; i++) {
        switch (cw_asm_get_arg_type(instruct->parameters[i], op_tab[instruct->instruct_code].type[i])) {
        case T_REG:
            instruct->coding_byte = (instruct->coding_byte << 2) + 1;
            break;
        case T_DIR:
            instruct->coding_byte = (instruct->coding_byte << 2) + 10;
            break;
        case T_IND:
            instruct->coding_byte = (instruct->coding_byte << 2) + 11;
            break;
        default:
            return (84);
        }
    }
    return (0);
}