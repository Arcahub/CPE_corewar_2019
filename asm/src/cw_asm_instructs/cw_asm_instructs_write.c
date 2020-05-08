/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instructs_write
*/

#include "instructs/cw_asm_instruct.h"
#include "instructs/cw_asm_instruct_write.h"

/*
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
}*/

void cw_asm_instructs_write(cw_asm_instruct_t *instructs_list, int fdout)
{
    int offset = 0;
    cw_asm_instruct_t *tmp = instructs_list;

    for (; tmp && tmp->next != NULL; tmp = tmp->next);
    for (; tmp; tmp = tmp->last) {
        if (tmp->instruct_code == -1)
            continue;
        CW_ASM_INSTRUCTS_WRITE_FP[tmp->instruct_code - 1](tmp, &instructs_list,
        fdout, &offset);
    }
}