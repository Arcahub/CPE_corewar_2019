/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_destroy
*/

#include "asm/cw_asm.h"
#include "asm/header/cw_asm_header.h"
#include "asm/instructs/cw_asm_instruct.h"
#include <fcntl.h>

void cw_asm_destroy(cw_asm_t *self)
{
    if (!self)
        return;
    cw_asm_header_destroy(self->header);
    while (self->instructs)
        cw_asm_instruct_destroy(self->instructs, &self->instructs);
    if (self->fdout)
        close(self->fdout);
    my_free(self);
}