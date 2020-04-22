/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_get_prog_size
*/

#include "cw_asm.h"
#include "instructs/cw_asm_instruct.h"

void cw_asm_get_prog_size(cw_asm_t *self)
{
    for (cw_asm_instruct_t *tmp = self->instructs; tmp; tmp = tmp->next) {
        if (tmp->instruct_code == -1)
            return;
        self->header->prog_size += 2;
        self->header->prog_size += tmp->instruct_size;
    }
}