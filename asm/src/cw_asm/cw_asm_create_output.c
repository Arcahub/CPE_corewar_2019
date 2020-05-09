/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_create_output
*/

#include "my/my.h"
#include "my/io.h"
#include "asm/cw_asm.h"
#include <fcntl.h>

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

int cw_asm_output_create(char *raw_path)
{
    char *path = cw_asm_compute_output_path(raw_path);
    int fd = 0;

    if (path == NULL)
        return (-1);
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0755);
    my_free(path);
    if (fd < 0)
        return (-1);
    return (fd);
}