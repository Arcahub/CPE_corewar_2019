/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_load_label
*/

#include "instructs/cw_asm_instruct.h"
#include "my.h"

static bool is_only_alphanumc(char c)
{
    if (c < 48 || (c > 57 && c < 97) || c > 122)
        return (false);
    return (true);
}

void cw_asm_instruct_load_label(cw_asm_instruct_t *instruct, char **line)
{
    int i = 0;

    while (**line == ' ' || **line == '\t')
        *line += 1;
    if (**line == '\0')
        return;
    for (; is_only_alphanumc((*line)[i]); i++);
    if ((*line)[i] != ':')
        return;
    instruct->label = my_strndup(*line, i);
    *line += i + 1;
}