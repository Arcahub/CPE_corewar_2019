/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_write
*/

#include <unistd.h>
#include "cw_asm.h"
#include "header/cw_asm_header.h"

void cw_asm_write(cw_asm_t *self)
{
    cw_asm_header_write(self->header, self->fdout);
}