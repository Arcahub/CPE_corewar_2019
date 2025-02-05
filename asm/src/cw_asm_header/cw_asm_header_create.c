/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_create
*/

#include "asm/header/cw_asm_header.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"

cw_asm_header_t *cw_asm_header_create(void)
{
    cw_asm_header_t *header = my_malloc(sizeof(cw_asm_header_t));

    if (!header)
        return (NULL);
    header->magic = 0;
    header->magic = u32_ne_to_be(COREWAR_EXEC_MAGIC);
    for (int i = 0; i < PROG_NAME_LENGTH + 2; i++)
        header->prog_name[i] = '\0';
    header->prog_size = 0;
    for (int j = 0; j < COMMENT_LENGTH + 2; j++)
        header->comment[j] = '\0';
    return (header);
}
