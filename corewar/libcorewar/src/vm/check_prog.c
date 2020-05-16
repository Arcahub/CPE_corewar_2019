/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** check_prog
*/

#include "corewar/corewar.h"

bool cw_vm_check_prog(cw_vm_t *self, cw_program_def_t *def)
{
    usize_t name_len = self->config.prog_name_length;
    usize_t name_off = 4;
    usize_t size_off = ((name_off + name_len + 1) / 4 + 1) * 4;
    usize_t comment_off = size_off + 4;
    usize_t comment_len = self->config.comment_length;
    usize_t data_off = ((comment_off + comment_len + 1) / 4 + 1) * 4;
    u32_t prog_size = 0;

    if (def->size < data_off)
        return (true);
    prog_size = u32_be_to_ne(*((u32_t*) &def->data[size_off]));
    if (def->size < data_off + prog_size)
        return (true);
    return (false);
}
