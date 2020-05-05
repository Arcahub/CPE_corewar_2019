/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_compile_header
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "header/cw_asm_header.h"
#include "my.h"

static bool cw_asm_header_load_compute_comment(cw_asm_header_t *header,
char *line)
{
    if (my_strcmp(line, COMMENT_CMD_STRING))
        return (false);
    line += my_strlen(COMMENT_CMD_STRING) + 1;
    while (*line == ' ' || *line == '\t')
        line += 1;
    my_strncpy(header->comment, line + 1, my_strlen(line + 1) - 1);
    return (true);
}

static bool cw_asm_header_load_compute_name(cw_asm_header_t *header, char *line)
{
    if (my_strcmp(line, NAME_CMD_STRING))
        return (false);
    line += my_strlen(NAME_CMD_STRING) + 1;
    while (*line == ' ' || *line == '\t')
        line += 1;
    my_strncpy(header->prog_name, line + 1, my_strlen(line + 1) - 1);
    return (true);
}

static int cw_asm_header_load_compute_line(cw_asm_header_t *header, char *line)
{
    while (*line == ' ' || *line == '\t')
        line += 1;
    if (cw_asm_header_load_compute_name(header, line))
        return (0);
    else if (cw_asm_header_load_compute_comment(header, line))
        return (0);
    else
        return (84);
}

int cw_asm_header_load(cw_asm_header_t *self, FILE *fdin)
{
    int ret = 0;
    char *line = my_get_line(fdin);
    int count = 0;

    for (; line && count != 2; line = my_get_line(fdin)) {
        if (*line == COMMENT_CHAR)
            continue;
        else if (!cw_asm_header_load_compute_line(self, line))
            count += 1;
        else {
            free(line);
            return (84);
        }
        free(line);
    }
    if (line)
        free(line);
    return (0);
}