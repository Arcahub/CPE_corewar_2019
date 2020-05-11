/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instructs_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/instructs/cw_asm_instruct_write.h"

void cw_asm_instructs_write(cw_asm_instruct_t *instructs_list, bufwriter_t *bw)
{
    int offset = 0;
    cw_asm_instruct_t *tmp = instructs_list;

    for (; tmp && tmp->next != NULL; tmp = tmp->next);
    for (; tmp; tmp = tmp->last) {
        if (tmp->instruct_code == -1)
            continue;
        CW_ASM_INSTRUCTS_WRITE_FP[tmp->instruct_code - 1](tmp, &instructs_list,
        bw, &offset);
    }
}
