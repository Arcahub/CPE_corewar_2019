/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_check_file
*/

#include "my/my.h"
#include "my/io.h"

bufreader_t *cw_asm_input_open(char *path)
{
    bufreader_t *bf = filereader_open(path, 64);

    return (bf);
}
