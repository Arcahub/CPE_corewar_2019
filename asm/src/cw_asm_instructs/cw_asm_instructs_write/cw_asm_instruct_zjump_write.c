/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_zjump_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"
#include <unistd.h>

static void cw_asm_instruct_write_args_zjump(cw_asm_instruct_t *zjump,
cw_asm_instruct_t **instructs_list, int *offset, bufwriter_t *bw)
{
    int value = 0;

    for (int i = 0; zjump->parameters[i]; i++) {
        switch (*zjump->parameters[i]) {
        case 'r':
            value = my_getnbr(zjump->parameters[i] + 1);
            bufwriter_write(bw, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = u16_ne_to_be(u32_ne_to_be((
            cw_asm_instruct_write_arg_direct(zjump,
            *instructs_list, *offset, i))));
            bufwriter_write(bw, &value, IND_SIZE);
            break;
        default:
            value = u16_ne_to_be(my_getnbr(zjump->parameters[i]));
            bufwriter_write(bw, &value, IND_SIZE);
        }
    }
}


void cw_asm_instruct_zjump_write(cw_asm_instruct_t *instruct,
    cw_asm_instruct_t **list, bufwriter_t *bw, int *offset)
{
    bufwriter_write(bw, &instruct->instruct_code, sizeof(char));
    cw_asm_instruct_write_args_zjump(instruct, list, offset, bw);
    *offset -= instruct->instruct_size;
}
