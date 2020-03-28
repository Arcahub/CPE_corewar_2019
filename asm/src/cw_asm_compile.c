/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_compile
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "cw_asm.h"

int leave_early(instruct_t *instructs_list, FILE *fdin, int fdout)
{
    if (instructs_list != NULL)
        cw_asm_free_instructs_list(instructs_list);
    close(fdout);
    fclose(fdin);
    return (84);
}

int cw_asm_compile(FILE *fdin, int fdout)
{
    header_t header;
    instruct_t *instructs_list = NULL;

    if (cw_asm_compile_header(fdin, &header) == 84 || \
    cw_asm_format_instructs(&instructs_list, fdin) == 84)
        return (leave_early(instructs_list, fdin, fdout));
    header.prog_size = cw_asm_get_prog_size(instructs_list);
    if (cw_asm_write_header(fdout, &header) == 84)
        return (leave_early(instructs_list, fdin, fdout));
    cw_asm_free_instructs_list(instructs_list);
    close(fdout);
    fclose(fdin);
    return (0);
}