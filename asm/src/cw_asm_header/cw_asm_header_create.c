/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_create
*/

#include "header/cw_asm_header.h"
#include <stdlib.h>

cw_asm_header_t *cw_asm_header_create(void)
{
    cw_asm_header_t *header = malloc(sizeof(cw_asm_header_t));

    if (!header)
        return (NULL);
    header->magic = COREWAR_EXEC_MAGIC;
    for (int i = 0; i < PROG_NAME_LENGTH + 1; i++)
        header->prog_name[i] = '\0';
    header->prog_size = 0;
    for (int i = 0; i < COMMENT_LENGTH + 1; i++)
        header->comment[i] = '\0';
    return (header);
}