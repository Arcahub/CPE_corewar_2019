/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_free
*/

#include "cw_asm.h"
#include <stdlib.h>

void cw_asm_free_parameters(instruct_t *instruct)
{
    for (int i = 0; instruct->parameters[i] != NULL; i++)
        free(instruct->parameters[i]);
}

void cw_asm_free_instructs_list(instruct_t *instruct)
{
    instruct_t *tmp = instruct;

    for (; instruct && tmp; instruct = tmp) {
        tmp = instruct->next;
        if (instruct->label != NULL)
            free(instruct->label);
        cw_asm_free_parameters(instruct);
        free(instruct);
    }
}