/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_load_instruct_args
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"

void cw_asm_instruct_check_args_len_err(cw_asm_instruct_t *instruct,
    cw_asm_error_context_t err_context, op_t op, int i)
{
    if (instruct->instruct_code - 1 < 0)
        return;
    if (i < op.nbr_args) {
        cw_asm_error_list(cw_asm_error_context_change_type(err_context, ERROR),
            "Not enough arguments", op.mnemonique);
    } else {
        cw_asm_error_list(cw_asm_error_context_change_type(err_context, ERROR),
            "Too many arguments", op.mnemonique);
    }
}

static char *cw_asm_instruct_clean_arg(char *arg)
{
    char *str = NULL;
    int i = 0;

    for (; arg[i] != '\0' && arg[i] != COMMENT_CHAR; i++);
    if (arg[i] != '\0') {
        arg = my_cstrndup(arg, i);
        str = arg;
    }
    arg = my_trimline(arg);
    if (str)
        my_free(str);
    return (arg);
}

void cw_asm_instruct_load_args(cw_asm_error_context_t err_context,
    cw_asm_instruct_t *instruct, char **line)
{
    char **args = str_to_word_array_sep(*line, SEPARATOR_CHAR);
    op_t op = op_tab[instruct->instruct_code - 1];
    int i = 0;

    if (args == NULL)
        return;
    for (; args[i]; i++);
    if (i != op.nbr_args || op.nbr_args > MAX_ARGS_NUMBER) {
        cw_asm_instruct_check_args_len_err(instruct, err_context, op, i);
        for (i = 0; args[i]; i++)
            my_free(args[i]);
        my_free(args);
        return;
    }
    for (i = 0; i < op.nbr_args; i++) {
        instruct->parameters[i] = cw_asm_instruct_clean_arg(args[i]);
        my_free(args[i]);
    }
    my_free(args);
    return;
}
