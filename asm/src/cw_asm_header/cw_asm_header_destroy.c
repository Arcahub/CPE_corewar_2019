/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_destroy
*/

#include "asm/header/cw_asm_header.h"
#include "my/my.h"

void cw_asm_header_destroy(cw_asm_header_t *self)
{
    if (!self)
        return;
    my_free(self);
}