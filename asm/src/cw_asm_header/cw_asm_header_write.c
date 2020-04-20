/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_header_write
*/

#include "header/cw_asm_header.h"

int cw_asm_header_write(cw_asm_header_t *self, int fdout)
{
    if (self->prog_name[0] == '\0' || self->comment[0] == '\0')
        return (84);
    printf("%s\n", self->prog_name);
    printf("%s\n", self->comment);
    printf("%ld\n", write(fdout, self, sizeof(header_t)));
    return (0);
}