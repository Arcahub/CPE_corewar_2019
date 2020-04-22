/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_destroy
*/

#include "cw_asm.h"
#include "header/cw_asm_header.h"
#include "instructs/cw_asm_instruct.h"
#include <stdlib.h>
#include <unistd.h>

void cw_asm_destroy(cw_asm_t *self)
{
    if (!self)
        return;
    cw_asm_header_destroy(self->header);
    while (self->instructs)
        cw_asm_instruct_destroy(self->instructs, &self->instructs);
    if (self->fdout >= 0)
        close(self->fdout);
    if (self->fdin)
        fclose(self->fdin);
    free(self);
}