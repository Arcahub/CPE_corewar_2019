/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_load_instruct_args
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"

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

void cw_asm_instruct_load_args(cw_asm_instruct_t *instruct, char **line)
{
    char **args = str_to_word_array_sep(*line, SEPARATOR_CHAR);
    int nbr_args = op_tab[instruct->instruct_code - 1].nbr_args;
    int i = 0;

    if (args == NULL)
        return;
    for (; args[i]; i++);
    if (i != nbr_args || nbr_args > MAX_ARGS_NUMBER) {
        for (i = 0; args[i]; i++)
            my_free(args[i]);
        my_free(args);
        return;
    }
    for (i = 0; i < nbr_args; i++) {
        instruct->parameters[i] = cw_asm_instruct_clean_arg(args[i]);
        my_free(args[i]);
    }
    my_free(args);
    return;
}
