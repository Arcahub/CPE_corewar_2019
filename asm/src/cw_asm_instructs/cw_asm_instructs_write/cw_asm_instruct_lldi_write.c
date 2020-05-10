/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_lldi_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include <unistd.h>

static void cw_asm_instruct_write_args_lldi(cw_asm_instruct_t *lldi,
    cw_asm_instruct_t **instructs_list, int *offset, int fdout)
{
    int value = 0;

    for (int i = 0; lldi->parameters[i]; i++) {
        switch (*lldi->parameters[i]) {
        case 'r':
            value = my_getnbr(lldi->parameters[i] + 1);
            write(fdout, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = u16_swap_endian(reverse_bytes((
            cw_asm_instruct_write_arg_direct(lldi,
            *instructs_list, *offset, i))));
            write(fdout, &value, IND_SIZE);
            break;
        default:
            value = u16_swap_endian(my_getnbr(lldi->parameters[i]));
            write(fdout, &value, IND_SIZE);
        }
    }
}

void cw_asm_instruct_lldi_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, int fdout, int *offset)
{
    write(fdout, &instruct->instruct_code, sizeof(char));
    write(fdout, &instruct->coding_byte, sizeof(char));
    cw_asm_instruct_write_args_lldi(instruct, list, offset, fdout);
    *offset -= instruct->instruct_size;
}
