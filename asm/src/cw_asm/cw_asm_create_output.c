/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_create_output
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

static char *cw_asm_compute_output_path(char *old_path)
{
    char *path = NULL;
    char *tmp = NULL;
    int length = my_strlen(old_path);

    if (length > 2)
        if (old_path[length - 1] == 's' && old_path[length - 2] == '.')
            length = length - 2;
    tmp = my_strndup(old_path, length);
    if (tmp == NULL)
        return (NULL);
    path = my_strcat(tmp, ".cor");
    free(tmp);
    if (path == NULL)
        return (NULL);
    return (path);
}

int cw_asm_output_create(char *raw_path)
{
    char *path = cw_asm_compute_output_path(raw_path);
    int fd = 0;

    if (path == NULL)
        return (-1);
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0755);
    free(path);
    if (fd < 0)
        return (-1);
    return (fd);
}