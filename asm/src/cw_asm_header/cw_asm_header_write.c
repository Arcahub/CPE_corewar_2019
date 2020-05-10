/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_header_write
*/

#include "asm/header/cw_asm_header.h"
#include "asm/cw_asm_tools.h"
#include "my/io.h"
#include <unistd.h>

int cw_asm_header_write(cw_asm_header_t *self, bufwriter_t *bw)
{
    if (self->prog_name[0] == '\0' || self->comment[0] == '\0')
        return (84);
    self->prog_size = u32_swap_endian(self->prog_size);
    bufwriter_write(bw, self, sizeof(cw_asm_header_t));
    return (0);
}