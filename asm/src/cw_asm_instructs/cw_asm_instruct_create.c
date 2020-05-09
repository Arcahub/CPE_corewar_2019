/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_create
*/

#include "asm/instructs/cw_asm_instruct.h"


cw_asm_instruct_t *cw_asm_instruct_create(cw_asm_instruct_t *head)
{
    cw_asm_instruct_t *self = my_malloc(sizeof(cw_asm_instruct_t));

    if (self == NULL)
        return (NULL);
    self->next = head;
    self->last = NULL;
    if (head != NULL)
        head->last = self;
    self->label = NULL;
    self->instruct_code = -1;
    self->coding_byte = 0;
    self->instruct_size = 0;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        self->parameters[i] = NULL;
    return (self);
}