/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_get_prog_size
*/

#include "cw_asm.h"

int cw_asm_get_instruct_size(instruct_t *instruct)
{
    printf("truc de ouf: %ld\n", sizeof(char));
    return (0);
}

int cw_asm_get_prog_size(instruct_t *instructs_list)
{
    int size = 0;

    for (instruct_t *tmp = instructs_list; tmp; tmp = tmp->next) {
        size += cw_asm_get_instruct_size(tmp);
    }
    return (size);
}