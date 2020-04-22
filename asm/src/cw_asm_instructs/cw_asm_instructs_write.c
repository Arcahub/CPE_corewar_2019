/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instructs_write
*/

#include "instructs/cw_asm_instruct.h"
#include "my.h"

void cw_asm_instructs_debug(cw_asm_instruct_t *instructs_list)
{
    for (cw_asm_instruct_t *tmp = instructs_list; tmp; tmp = tmp->next) {
        if (tmp->label)
            printf("%s:", tmp->label);
        if (tmp->instruct_code == -1) {
            printf("\n");
            continue;
        }
        printf("%s ", op_tab[tmp->instruct_code - 1].mnemonique);
        printf("%s", tmp->parameters[0]);
        for (int i = 1; tmp->parameters[i]; i++)
            printf(",%s", tmp->parameters[i]);
        printf("\n");
    }
}

int cw_asm_instruct_get_label_offset(char *param, cw_asm_instruct_t *instructs_list,
int offset)
{
    cw_asm_instruct_t *tmp = instructs_list;
    int offset2 = 0;

    if (*param == '%')
        param += 1;
    if (*param == ':')
        param += 1;
    printf("%d\n", offset);
    for (; tmp->next; tmp = tmp->next);
    for (; tmp; tmp = tmp->last) {
        if (tmp->label && !my_strncmp(tmp->label, param, my_strlen(param)))
            return (offset + offset2);
        if (tmp->instruct_code != -1)
            offset2 += tmp->instruct_size;
        printf("2OFF: %d\n", offset2);
    }
    return (0);
}

int cw_asm_instruct_write_arg_direct(cw_asm_instruct_t *instruct, cw_asm_instruct_t *instructs_list,
int offset, int i)
{
    int value = 0;
    char *param = instruct->parameters[i];

    if (*(param + 1) != LABEL_CHAR) {
        value = my_getnbr(param + 1);
        return (value);
    }
    value = cw_asm_instruct_get_label_offset(param, instructs_list, offset);
    printf("label offset : %d\n", value);
    return (value);
}

void cw_asm_instruct_write_args(cw_asm_instruct_t *instruct,
cw_asm_instruct_t *instructs_list, int offset, int fdout)
{
    int value = 0;

    for (int i = 0; instruct->parameters[i]; i++) {
        switch (*instruct->parameters[i]) {
        case 'r':
            value = my_getnbr(instruct->parameters[i] + 1);
            write(fdout, &value, sizeof(char));
            break;
        case DIRECT_CHAR:
            value = cw_asm_instruct_write_arg_direct(instruct, instructs_list,
            offset, i);
            write(fdout, &value, DIR_SIZE);
            break;
        default:
            value = my_getnbr(instruct->parameters[i]);
            write(fdout, &value, IND_SIZE);
        }
        printf("par: %s : val! %d\n", instruct->parameters[i], value);
    }
}

void cw_asm_instructs_write(cw_asm_instruct_t *instructs_list, int fdout)
{
    int offset = 0;
    cw_asm_instruct_t *tmp = instructs_list;

    for (; tmp->next != NULL; tmp = tmp->next);
    for (; tmp; tmp = tmp->last) {
        if (tmp->instruct_code == -1)
            continue;
        write(fdout, &tmp->instruct_code, sizeof(char));
        if (!(tmp->instruct_code == -1 || tmp->instruct_code == 1 ||
        tmp->instruct_code == 9 || tmp->instruct_code == 12 ||
        tmp->instruct_code == 15))
            write(fdout, &tmp->coding_byte, sizeof(char));
        cw_asm_instruct_write_args(tmp, instructs_list, offset, fdout);
        offset -= tmp->instruct_size;
    }
}