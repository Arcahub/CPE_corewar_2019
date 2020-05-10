/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_display_error
*/

#include "asm/cw_asm.h"
#include "asm/error/cw_asm_error.h"
#include "my/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static char TYPE_COLOR[3] = {RED, MAGENTA, BLUE};
static char *TYPE_STR[3] = {"ERROR ", "WARNING ", "NOTE "};

static void cw_asm_error_type(cw_asm_error_context_t context)
{
    cw_asm_error_color_t color = {TYPE_COLOR[(int)context.type], true};

    cw_asm_error_put_str(TYPE_STR[(int)context.type], color);
    if (context.line >= 0) {
        cw_asm_error_put(color, "(%d", context.line);
        if (context.column >= 0)
            cw_asm_error_put(color, ":%d", context.column);
        cw_asm_error_put_str(") ", color);
    }
    cw_asm_error_put_str(": ", color);
}

static void cw_asm_error_content(cw_asm_error_content_t content)
{
    switch (content.type)
    {
        case INT:
            cw_asm_error_put_nb(*((int *)(content.content)), content.color);
            break;
        case CHAR:
            cw_asm_error_put_char(*((char *)(content.content)), content.color);
            break;
        case STRING:
            cw_asm_error_put_str(*((char **)(content.content)), content.color);
            break;
    }
}

static void cw_asm_error_line(cw_asm_error_context_t context)
{
    int i = 0;
   cw_asm_error_color_t color = {RESET, false};
   cw_asm_error_color_t error = {TYPE_COLOR[(int)context.type], false};

    cw_asm_error_put_str("    > ", color);
    if (context.column >= 0) {
        for (i = 0; i < context.column && context.str_line[i]; i++)
            cw_asm_error_put_char(context.str_line[i], color);
        cw_asm_error_put_char(context.str_line[i], error);
        for (i++ ;context.str_line[i]; i++)
            cw_asm_error_put_char(context.str_line[i], color);
    } else {
        cw_asm_error_put_str(context.str_line, color);
    }
    cw_asm_error_put_char('\n', color);
}

void cw_asm_error(cw_asm_error_context_t context,
    cw_asm_error_content_t content)
{
    cw_asm_error_color_t color = {RESET, false};

    cw_asm_error_type(context);
    cw_asm_error_content(content);
    cw_asm_error_put_char('\n', color);
    if (context.str_line)
        cw_asm_error_line(context);
    cw_asm_error_put_char('\n', color);
}

void cw_asm_error_list(cw_asm_error_context_t context, char *str, ...)
{
    va_list arg;
    cw_asm_error_color_t color = {RESET, false};

    cw_asm_error_type(context);
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
    cw_asm_error_put_char('\n', color);
    if (context.str_line)
        cw_asm_error_line(context);
    cw_asm_error_put_char('\n', color);
}