/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_compile_instructs
*/

#include "my.h"
#include "cw_asm.h"
#include "instructs/cw_asm_instruct.h"
#include <unistd.h>
#include <stdlib.h>

static cw_asm_instruct_t *cw_asm_instruct_load_compute_line(
cw_asm_instruct_t *last, char *line)
{
    cw_asm_instruct_t *instruct = cw_asm_instruct_create(last);

    // cw_asm_instruct_load_label(instruct, &line);
    // cw_asm_instruct_load_cmd(instruct, &line);
    // cw_asm_instruct_load_args(instruct, &line);
}

int cw_asm_instruct_load(cw_asm_instruct_t **instructs_list, FILE *fdin)
{
    char *line = my_get_line(fdin);
    cw_asm_instruct_t *tmp = NULL;

    for (; line; line = my_get_line(fdin)) {
        if (*line == '0')
            continue;
        tmp = cw_asm_instruct_load_compute_line(*instructs_list, line);
        printf("%s\n", line);
        free(line);
    }
    return (0);
}