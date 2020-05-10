/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_load_label
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "my/my.h"

static bool cw_asm_instruct_load_label_is_valid_char(char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++)
        if (LABEL_CHARS[i] == c)
            return (true);
    return (false);
}

void cw_asm_instruct_load_label(cw_asm_instruct_t *instruct, char **line)
{
    int i = 0;

    while (**line == ' ' || **line == '\t')
        *line += 1;
    if (**line == '\0')
        return;
    for (; cw_asm_instruct_load_label_is_valid_char((*line)[i]); i++);
    if ((*line)[i] != ':')
        return;
    instruct->label = my_cstrndup(*line, i);
    *line += i + 1;
}
