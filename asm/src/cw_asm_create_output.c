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

char *cw_asm_compute_output_path(char *old_path)
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

int cw_asm_create_output(char *old_path)
{
    char *path = cw_asm_compute_output_path(old_path);
    int fd = 0;

    if (path == NULL)
        return (84);
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0755);
    free(path);
    if (fd < 0)
        return (84);
    return (fd);
}