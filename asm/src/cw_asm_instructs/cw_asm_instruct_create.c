/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_create
*/

#include "instructs/cw_asm_instruct.h"
#include <stdlib.h>

cw_asm_instruct_t *cw_asm_instruct_create(cw_asm_instruct_t *last)
{
    cw_asm_instruct_t *self = malloc(sizeof(cw_asm_instruct_t));

    if (self == NULL)
        return (NULL);
    self->next = last;
    self->label = NULL;
    self->instruct_code = 0;
    self->coding_byte = 0;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        self->parameters[i] = NULL;
    return (self);
}