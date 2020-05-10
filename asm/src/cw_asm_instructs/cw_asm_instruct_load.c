/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_compile_instructs
*/

#include "my/my.h"
#include "asm/cw_asm.h"
#include "asm/instructs/cw_asm_instruct.h"
#include "asm/error/cw_asm_error.h"
#include <unistd.h>

static cw_asm_instruct_t *cw_asm_instruct_load_compute_line(
    cw_asm_error_context_t err_context,
    cw_asm_instruct_t *last, char *line)
{
    cw_asm_instruct_t *instruct = cw_asm_instruct_create(last);

    if (!instruct)
        return (NULL);
    cw_asm_instruct_load_label(instruct, &line);
    cw_asm_instruct_load_cmd(instruct, &line);
    if (instruct->label == NULL && instruct->instruct_code == -1) {
        cw_asm_instruct_destroy(instruct, NULL);
        return (NULL);
    }
    cw_asm_instruct_load_args(instruct, &line);
    if (cw_asm_instruct_check_args(err_context, instruct)) {
        cw_asm_instruct_destroy(instruct, NULL);
        return (NULL);
    }
    return (instruct);
}

int cw_asm_instruct_load(cw_asm_instruct_t **instructs_list, bufreader_t *fdin)
{
    char *line = bufreader_read_line(fdin);
    cw_asm_instruct_t *tmp = NULL;
    cw_asm_error_context_t err_context = {-1, -1, 0, 0};
    int last_char = 0;

    for (; line; line = bufreader_read_line(fdin)) {
        last_char = my_cstrlen(line) - 1;
        line[last_char] = (line[last_char] == '\n') ? '\0' : line[last_char];
        if (cw_asm_is_line_useless(line)) {
            my_free(line);
            continue;
        }
        tmp = cw_asm_instruct_load_compute_line(err_context,
            *instructs_list, line);
        free(line);
        if (tmp == NULL)
            return (84);
        *instructs_list = tmp;
        err_context.line++;
    }
    return (0);
}