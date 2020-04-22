/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_load_instruct_args
*/

#include "instructs/cw_asm_instruct.h"
#include "my.h"
#include <stdlib.h>

void cw_asm_instruct_load_args(cw_asm_instruct_t *instruct, char **line)
{
    char **args = str_to_word_array_sep(*line, SEPARATOR_CHAR);
    int nbr_args = op_tab[instruct->instruct_code - 1].nbr_args;
    int i = 0;

    if (args == NULL)
        return;
    for (; args[i]; i++);
    if (i != nbr_args || nbr_args > MAX_ARGS_NUMBER) {
        for (int j = 0; args[i]; i++)
            free(args[i]);
        free(args);
        return;
    }
    for (i = 0; i < nbr_args; i++) {
        instruct->parameters[i] = my_strdup(args[i]);
        free(args[i]);
    }
    free(args);
    return;
}