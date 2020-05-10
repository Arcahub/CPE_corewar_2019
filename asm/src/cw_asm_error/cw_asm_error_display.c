/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_display_error
*/

#include "asm/cw_asm.h"
#include "asm/error/cw_asm_error.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cw_asm_error_put_str(char *str, cw_asm_error_color_t color)
{
    int len = my_cstrlen(str);

    cw_asm_error_color(color);
    write(2, str, len);
    cw_asm_error_color_reset();
}

void cw_asm_error_put_nb(int nb, cw_asm_error_color_t color)
{
    char *nb_str = my_itoa(nb);
    int len = my_cstrlen(nb_str);

    cw_asm_error_color(color);
    write(2, nb_str, len);
    cw_asm_error_color_reset();
    free(nb_str);
}

void cw_asm_error_put_char(char c, cw_asm_error_color_t color)
{
    cw_asm_error_color(color);
    write(2, &c, 1);
    cw_asm_error_color_reset();
}

void cw_asm_error_put_var(cw_asm_error_color_t color,
    char type, va_list arg)
{
    switch (type) {
        case 'd':
            cw_asm_error_put_nb(va_arg(arg, int), color);
            break;
        case 'c':
            cw_asm_error_put_char(va_arg(arg, int), color);
            break;
        case 's':
            cw_asm_error_put_str(va_arg(arg, char *), color);
            break;
        default:
            cw_asm_error_put_char(type, color);
            break;
    }
}

void cw_asm_error_put(cw_asm_error_color_t color,
    char *str, ...)
{
    va_list arg;

    va_start(arg, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            cw_asm_error_put_var(color, str[i], arg);
        } else {
            cw_asm_error_put_char(str[i], color);
        }
    }
    va_end(arg);
}
