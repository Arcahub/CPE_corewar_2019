/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_compile_header
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "asm/header/cw_asm_header.h"
#include "asm/cw_asm.h"
#include "my/my.h"

static bool cw_asm_header_load_compute_comment(cw_asm_header_t *header,
    char *line)
{
    if (my_cstrncmp(line, COMMENT_CMD_STRING, my_cstrlen(COMMENT_CMD_STRING)))
        return (false);
    line += my_cstrlen(COMMENT_CMD_STRING) + 1;
    while (*line == ' ' || *line == '\t')
        line += 1;
    my_cstrncpy(header->comment, line + 1, my_cstrlen(line + 1) - 1);
    return (true);
}

static bool cw_asm_header_load_compute_name(cw_asm_header_t *header, char *line)
{
    if (my_cstrncmp(line, NAME_CMD_STRING, my_cstrlen(NAME_CMD_STRING)))
        return (false);
    line += my_cstrlen(NAME_CMD_STRING) + 1;
    while (*line == ' ' || *line == '\t')
        line += 1;
    my_cstrncpy(header->prog_name, line + 1, my_cstrlen(line + 1) - 1);
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

int cw_asm_header_load(cw_asm_header_t *self, bufreader_t *fdin)
{
    char *ln = bufreader_read_line(fdin);
    int count = 0;
    int last_char = 0;

    for (; ln && count != 2; ln = bufreader_read_line(fdin)) {
        last_char = (isize_t ) my_cstrlen(ln) - 1 < 0 ? 0 : my_cstrlen(ln) - 1;
        ln[last_char] = (ln[last_char] == '\n') ? '\0' : ln[last_char];
        if (cw_asm_is_line_useless(ln))
            continue;
        else if (!cw_asm_header_load_compute_line(self, ln))
            count += 1;
        else {
            my_free(ln);
            return (84);
        }
        my_free(ln);
    }
    if (ln)
        my_free(ln);
    return (0);
}
