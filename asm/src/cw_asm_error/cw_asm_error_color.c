/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_error_color_reset
*/

#include "asm/cw_asm.h"
#include "asm/error/cw_asm_error.h"
#include <unistd.h>

void cw_asm_error_color(cw_asm_error_color_t color)
{
    char str_color[7] = {'\033', '[', '0', ';', '3', '0', 'm'};

    if (color.color == RESET) {
        write(2, "\033[0m", 4);
        return;
    }
    if (color.bold)
        str_color[2] = '1';
    str_color[5] = color.color + '0';
    write(2, str_color, 7);
}

void cw_asm_error_color_reset(void)
{
    write(2, "\033[0m", 4);
}