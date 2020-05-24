/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_load_cmd
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "my/my.h"

static bool is_only_alphanumc(char c)
{
    if (c < 48 || (c > 57 && c < 97) || c > 122)
        return (false);
    return (true);
}

void cw_asm_instruct_load_cmd(cw_asm_instruct_t *instruct, char **line)
{
    int i = 0;
    bool cmd_exist = false;
    int j = 0;

    while (**line == ' ' || **line == '\t')
        *line += 1;
    if (**line == '\0')
        return;
    for (; is_only_alphanumc((*line)[i]); i++);
    if ((*line)[i] != ' ' && (*line)[i] != '\t')
        return;
    for (; OP_TAB[j].mnemonique && !cmd_exist; j++) {
        if (!my_cstrncmp(OP_TAB[j].mnemonique, *line, i))
            cmd_exist = true;
    }
    if (cmd_exist) {
        instruct->instruct_code = j;
        *line += i + 1;
    }
}
