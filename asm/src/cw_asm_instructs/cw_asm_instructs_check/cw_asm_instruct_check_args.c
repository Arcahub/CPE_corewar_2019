/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_args
*/

#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"
#include "asm/instructs/cw_asm_instruct_check.h"

static char cw_asm_instruct_check_args_get_type(
    cw_asm_error_context_t err_context, char *parameter)
{
    int tmp = 0;

    tmp = cw_asm_instruct_check_reg(parameter);
    if (tmp) {
        if (tmp == 2)
            return (0);
        return (T_REG);
    }
    tmp = cw_asm_instruct_check_dir_ind(err_context, parameter);
    return (tmp);
}

static op_t cw_asm_instruct_check_args_get_op(cw_asm_instruct_t *instruct)
{
    char ins = instruct->instruct_code;
    op_t op = {0};

    if (ins == -1)
        return ((op_t){0});
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (ins == op_tab[i].code)
            op = op_tab[i];
    return (op);
}

static int cw_asm_instruct_check_args_param(cw_asm_error_context_t err_context,
    char *parameter, op_t op, int index)
{
    args_type_t valid_types = op.type[index];
    args_type_t type = cw_asm_instruct_check_args_get_type(err_context, parameter);

    if ((valid_types & type))
        return (0);
    return (1);
}

int cw_asm_instruct_check_args(cw_asm_error_context_t err_context,
    cw_asm_instruct_t *instruct)
{
    char **parameters = instruct->parameters;
    op_t op = cw_asm_instruct_check_args_get_op(instruct);

    if (instruct->instruct_code == -1)
        return (0);
    if (op.mnemonique == 0)
        return (1);
    for (int i = 0; instruct->parameters[i] && i < MAX_ARGS_NUMBER; i++) {
        if (i > op.nbr_args ||
            cw_asm_instruct_check_args_param(err_context,
                parameters[i], op, i))
            return (1);
    }
    return (0);
}