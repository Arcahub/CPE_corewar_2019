/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_sti_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"
#include <unistd.h>

static void cw_asm_instruct_write_args_sti(cw_asm_instruct_t *sti,
cw_asm_instruct_t **instructs_list, int *offset, bufwriter_t *bw)
{
    int value = 0;

    for (int i = 0; sti->parameters[i]; i++) {
        switch (*sti->parameters[i]) {
        case 'r':
            value = my_getnbr(sti->parameters[i] + 1);
            bufwriter_write(bw, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = u16_ne_to_be(u32_ne_to_be((
            cw_asm_instruct_write_arg_direct(sti,
            *instructs_list, *offset, i))));
            bufwriter_write(bw, &value, IND_SIZE);
            break;
        default:
            value = u16_ne_to_be(my_getnbr(sti->parameters[i]));
            bufwriter_write(bw, &value, IND_SIZE);
        }
    }
}

void cw_asm_instruct_sti_write(cw_asm_instruct_t *instruct,
    cw_asm_instruct_t **list, bufwriter_t *bw, int *offset)
{
    bufwriter_write(bw, &instruct->instruct_code, sizeof(char));
    bufwriter_write(bw, &instruct->coding_byte, sizeof(char));
    cw_asm_instruct_write_args_sti(instruct, list, offset, bw);
    *offset -= instruct->instruct_size;
}
