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

static void cw_asm_instruct_load_err_instruct(
    cw_asm_error_context_t err_context)
{
    cw_asm_error_list(cw_asm_error_context_change_type(err_context, ERROR),
            "Unknown instruction");
}

static cw_asm_instruct_t *cw_asm_instruct_load_compute_line(
    cw_asm_error_context_t err_context,
    cw_asm_instruct_t *last, char *line)
{
    cw_asm_instruct_t *instruct = cw_asm_instruct_create(last);

    cw_asm_error_context_add(&err_context, line);
    if (!instruct)
        return (NULL);
    cw_asm_instruct_load_label(instruct, &line);
    cw_asm_instruct_load_cmd(instruct, &line);
    if (instruct->label == NULL && instruct->instruct_code == -1) {
        cw_asm_instruct_load_err_instruct(err_context);
        cw_asm_instruct_destroy(instruct, NULL);
        return (NULL);
    }
    cw_asm_instruct_load_args(err_context, instruct, &line);
    if (cw_asm_instruct_check_args(err_context, instruct)) {
        cw_asm_instruct_destroy(instruct, NULL);
        return (NULL);
    }
    return (instruct);
}

int cw_asm_instruct_load(cw_asm_instruct_t **instructs_list, bufreader_t *fdin)
{
    char *ln = bufreader_read_line(fdin);
    cw_asm_instruct_t *tmp = NULL;
    cw_asm_error_context_t err_context = {-1, -1, 0, 0};
    int last_char = 0;

    for (; ln; ln = bufreader_read_line(fdin)) {
        last_char = (isize_t) my_cstrlen(ln) - 1 < 0 ? 0 : my_cstrlen(ln) - 1;
        ln[last_char] = (ln[last_char] == '\n') ? '\0' : ln[last_char];
        if (cw_asm_is_line_useless(ln)) {
            my_free(ln);
            continue;
        }
        tmp = cw_asm_instruct_load_compute_line(err_context,
            *instructs_list, ln);
        my_free(ln);
        if (tmp == NULL)
            return (84);
        *instructs_list = tmp;
    }
    return (0);
}
