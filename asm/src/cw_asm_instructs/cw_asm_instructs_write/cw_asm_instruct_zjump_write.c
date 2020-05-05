/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_zjump_write
*/

#include "instructs/cw_asm_instruct.h"
#include "tools.h"
#include "my.h"
#include <unistd.h>

static void cw_asm_instruct_write_args_zjump(cw_asm_instruct_t *zjump,
cw_asm_instruct_t **instructs_list, int *offset, int fdout)
{
    int value = 0;

    for (int i = 0; zjump->parameters[i]; i++) {
        switch (*zjump->parameters[i]) {
        case 'r':
            value = my_getnbr(zjump->parameters[i] + 1);
            write(fdout, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = (cw_asm_instruct_write_arg_direct(zjump,
            *instructs_list, *offset, i));
            write(fdout, &value, IND_SIZE);
            break;
        default:
            value = reverse_bytes16(my_getnbr(zjump->parameters[i]));
            write(fdout, &value, IND_SIZE);
        }
    }
}


void cw_asm_instruct_zjump_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, int fdout, int *offset)
{
    write(fdout, &instruct->instruct_code, sizeof(char));
    cw_asm_instruct_write_args_zjump(instruct, list, offset, fdout);
    *offset -= instruct->instruct_size;
}