/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_fork_write
*/

#include "instructs/cw_asm_instruct.h"
#include "tools.h"
#include <unistd.h>

void cw_asm_instruct_fork_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, int fdout, int *offset)
{
    int value = 0;

    write(fdout, &instruct->instruct_code, sizeof(char));
    value = reverse_bytes16(reverse_bytes((
    cw_asm_instruct_write_arg_direct(instruct,
    *list, *offset, 0))));
    write(fdout, &value, IND_SIZE);
    *offset -= instruct->instruct_size;
}