/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_destroy
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "my/my.h"

static void cw_asm_instruct_isolate(cw_asm_instruct_t *self,
    cw_asm_instruct_t **list)
{
    cw_asm_instruct_t *tmp = *list;

    if (tmp == self) {
        *list = self->next;
        return;
    }
    for (; tmp && tmp->next != self; tmp = tmp->next);
    if (!tmp)
        return;
    tmp->next = self->next;
}

void cw_asm_instruct_destroy(cw_asm_instruct_t *self, cw_asm_instruct_t **list)
{
    if (!self)
        return;
    if (list != NULL)
        cw_asm_instruct_isolate(self, list);
    if (self->label)
        my_free(self->label);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (self->parameters[i])
            my_free(self->parameters[i]);
    }
    my_free(self);
}
