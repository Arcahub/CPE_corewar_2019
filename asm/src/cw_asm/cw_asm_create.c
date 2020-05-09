/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_create
*/

#include "asm/cw_asm.h"
#include "asm/header/cw_asm_header.h"

static char *cw_asm_compute_output_path(char *old_path)
{
    char *path = NULL;
    char *tmp = NULL;
    int length = my_cstrlen(old_path);

    if (length > 2)
        if (old_path[length - 1] == 's' && old_path[length - 2] == '.')
            length = length - 2;
    tmp = my_cstrndup(old_path, length);
    if (tmp == NULL)
        return (NULL);
    path = my_format("%s%s", tmp, ".cor");
    my_free(tmp);
    if (path == NULL)
        return (NULL);
    return (path);
}

cw_asm_t *cw_asm_create(char *path)
{
    cw_asm_t *asm_s = my_malloc(sizeof(cw_asm_t));

    if (asm_s == NULL)
        return (NULL);
    asm_s->header = cw_asm_header_create();
    asm_s->instructs = NULL;
    asm_s->fdin = cw_asm_input_open(path);
    if (asm_s->header == NULL || asm_s->fdin == NULL) {
        cw_asm_destroy(asm_s);
        return (NULL);
    }
    asm_s->output_path = cw_asm_compute_output_path(path);
    asm_s->output_buff.len = 0;
    asm_s->output_buff.data = NULL;
    asm_s->bw = cw_asm_output_create(&asm_s->output_buff);
    if (asm_s->bw == NULL) {
        cw_asm_destroy(asm_s);
        return (NULL);
    }
    return (asm_s);
}