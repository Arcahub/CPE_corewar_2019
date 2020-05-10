/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_ldi_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"
#include <unistd.h>

static void cw_asm_instruct_write_args_ldi(cw_asm_instruct_t *ldi,
cw_asm_instruct_t **instructs_list, int *offset, bufwriter_t *bw)
{
    int value = 0;

    for (int i = 0; ldi->parameters[i]; i++) {
        switch (*ldi->parameters[i]) {
        case 'r':
            value = my_getnbr(ldi->parameters[i] + 1);
            bufwriter_write(bw, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = u16_swap_endian(u32_swap_endian((
            cw_asm_instruct_write_arg_direct(ldi,
            *instructs_list, *offset, i))));
            bufwriter_write(bw, &value, IND_SIZE);
            break;
        default:
            value = u16_swap_endian(my_getnbr(ldi->parameters[i]));
            bufwriter_write(bw, &value, IND_SIZE);
        }
    }
}

void cw_asm_instruct_ldi_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset)
{
    bufwriter_write(bw, &instruct->instruct_code, sizeof(char));
    bufwriter_write(bw, &instruct->coding_byte, sizeof(char));
    cw_asm_instruct_write_args_ldi(instruct, list, offset, bw);
    *offset -= instruct->instruct_size;
}