/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_write_args
*/

#include "instructs/cw_asm_instruct.h"
#include "tools.h"
#include "my.h"
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
        if (tmp->label && !my_strncmp(tmp->label, param, my_strlen(param)))
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
        value = reverse_bytes(my_getnbr(param + 1));
        return (value);
    }
    value = cw_asm_instruct_get_label_offset(param, instructs_list, offset);
    return (reverse_bytes(value));
}

void cw_asm_instruct_write_args(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **instructs_list, int *offset, int fdout)
{
    int value = 0;

    for (int i = 0; instruct->parameters[i]; i++) {
        switch (*instruct->parameters[i]) {
        case 'r':
            value = my_getnbr(instruct->parameters[i] + 1);
            write(fdout, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = cw_asm_instruct_write_arg_direct(instruct, *instructs_list,
            *offset, i);
            write(fdout, &value + 4 - DIR_SIZE, DIR_SIZE);
            break;
        default:
            value = reverse_bytes16(my_getnbr(instruct->parameters[i]));
            write(fdout, &value, IND_SIZE);
        }
    }
}