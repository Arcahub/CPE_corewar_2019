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

static int cw_asm_header_check_arg(char *str)
{
    if (my_strlen(str) < 4)
        return (84);
    if (str[0] != ' ')
        return (84);
    if (str[1] != '"' || str[my_strlen(str) - 1] != '"')
        return (84);
    return (0);
}

static int cw_asm_header_compute_line(char *line, cw_asm_header_t *self)
{
    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0) {
        if (cw_asm_header_check_arg(line + my_strlen(NAME_CMD_STRING)) == 84)
            return (84);
        else {
            my_strncpy(self->prog_name, line + my_strlen(NAME_CMD_STRING) \
            + 2, my_strlen(line + my_strlen(NAME_CMD_STRING)) - 3);
        }
    } else if (my_strncmp(line, COMMENT_CMD_STRING, \
    my_strlen(COMMENT_CMD_STRING)) == 0) {
        if (cw_asm_header_check_arg(line + my_strlen(COMMENT_CMD_STRING)) == 84)
            return (84);
        else
            my_strncpy(self->comment, line + my_strlen(COMMENT_CMD_STRING) \
            + 2, my_strlen(line + my_strlen(COMMENT_CMD_STRING)) - 3);
    } else
        return (84);
    return (0);
}

int cw_asm_header_load(cw_asm_header_t *self, FILE *fdin)
{
    int ret = 0;
    char *line = my_get_line(fdin);

    for (; line && ret == 0 && (self->prog_name[0] == '\0' || \
    self->comment[0] == '\0'); line = my_get_line(fdin)) {
        if (*line == COMMENT_CMD_STRING[0] || *line == NAME_CMD_STRING[0])
            ret = cw_asm_header_compute_line(line, self);
        else if (*line != '\0' && *line != COMMENT_CHAR) {
            free(line);
            return (84);
        }
        free(line);
    }
    if (line)
        free(line);
    if (ret == 84)
        return (84);
    return (0);
}