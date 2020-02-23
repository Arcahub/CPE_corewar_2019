/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_compile
*/

#include <unistd.h>
#include <stdio.h>
#include "cw_asm.h"

int cw_asm_compile(FILE *fdin, int fdout)
{
    header_t header;
    if (cw_asm_compile_header(fdin, fdout, &header) == 84) {
        close(fdout);
        fclose(fdin);
        return (84);
    }
    if (write_header(fdout, &header) == 84) {
        close(fdout);
        fclose(fdin);
    }
    close(fdout);
    fclose(fdin);
    return (0);
}