/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_write_args
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include "my/my.h"
#include <unistd.h>

int cw_asm_instruct_get_label_offset(char *param,
cw_asm_instruct_t *instructs_list, int offset)
{
    cw_asm_instruct_t *tmp = instructs_list;
    int offset2 = 0;

    param = (*param == '%') ? param + 1 : param;
    param = (*param == ':') ? param + 1 : param;
    for (; tmp && tmp->next; tmp = tmp->next);
    for (; tmp; tmp = tmp->last) {
        if (tmp->label && !my_cstrncmp(tmp->label, param, my_cstrlen(param)))
            return (offset + offset2);
        if (tmp->instruct_code != -1)
            offset2 += tmp->instruct_size;
    }
    return (0);
}

int cw_asm_instruct_write_arg_direct(cw_asm_instruct_t *instruct,
cw_asm_instruct_t *instructs_list, int offset, int i)
{
    int value = 0;
    char *param = instruct->parameters[i];

    if (*(param + 1) != LABEL_CHAR) {
        value = u32_swap_endian(my_getnbr(param + 1));
        return (value);
    }
    value = cw_asm_instruct_get_label_offset(param, instructs_list, offset);
    return (u32_swap_endian(value));
}

void cw_asm_instruct_write_args(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **instructs_list, int *offset, bufwriter_t *bw)
{
    int value = 0;

    for (int i = 0; instruct->parameters[i]; i++) {
        switch (*instruct->parameters[i]) {
        case 'r':
            value = my_getnbr(instruct->parameters[i] + 1);
            bufwriter_write(bw, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = cw_asm_instruct_write_arg_direct(instruct, *instructs_list,
            *offset, i);
            bufwriter_write(bw, &value + 4 - DIR_SIZE, DIR_SIZE);
            break;
        default:
            value = u16_swap_endian(my_getnbr(instruct->parameters[i]));
            bufwriter_write(bw, &value, IND_SIZE);
        }
    }
}