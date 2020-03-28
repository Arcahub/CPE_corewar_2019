/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_write
*/

#include <unistd.h>
#include "cw_asm.h"

int cw_asm_write_header(int fdout, header_t *header)
{
    if (header->prog_name[0] == '\0' || header->comment[0] == '\0')
        return (84);
    printf("%s\n", header->prog_name);
    printf("%s\n", header->comment);
    printf("%ld\n", write(fdout, header, sizeof(header_t)));
    return (0);
}