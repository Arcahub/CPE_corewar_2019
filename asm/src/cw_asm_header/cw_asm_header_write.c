/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_header_write
*/

#include "header/cw_asm_header.h"
#include "tools.h"
#include <unistd.h>

int cw_asm_header_write(cw_asm_header_t *self, int fdout)
{
    if (self->prog_name[0] == '\0' || self->comment[0] == '\0')
        return (84);
    self->prog_size = reverse_bytes(self->prog_size);
    write(fdout, self, sizeof(cw_asm_header_t));
    return (0);
}