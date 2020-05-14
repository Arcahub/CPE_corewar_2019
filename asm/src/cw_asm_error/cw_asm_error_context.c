/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_check_display_error
*/

#include "asm/cw_asm.h"
#include "asm/error/cw_asm_error.h"
#include "my/my.h"

cw_asm_error_context_t cw_asm_error_context_set(int line, int column,
    char type, char *str_line)
{
    cw_asm_error_context_t context = {0};

    context.line = line;
    context.column = column;
    context.type = type;
    context.str_line = str_line;
    return (context);
}

cw_asm_error_context_t cw_asm_error_context_add(
    cw_asm_error_context_t *context, char *str_line)
{
    context->line++;
    context->str_line = str_line;
    return (*context);
}

cw_asm_error_context_t cw_asm_error_context_change_type(
    cw_asm_error_context_t context, char type)
{
    context.type = type;
    return (context);
}