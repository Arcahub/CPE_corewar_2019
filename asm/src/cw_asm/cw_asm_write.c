/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_write
*/

#include <unistd.h>
#include "asm/cw_asm.h"
#include "asm/header/cw_asm_header.h"
#include "asm/instructs/cw_asm_instruct.h"
#include <fcntl.h>

void cw_asm_write(cw_asm_t *self)
{
    int fdout = open(self->output_path, O_WRONLY | O_CREAT | O_TRUNC, 0755);

    if (fdout < 0)
        return;
    cw_asm_get_prog_size(self);
    cw_asm_header_write(self->header, self->bw);
    cw_asm_instructs_write(self->instructs, self->bw);
    bufwriter_flush(self->bw);
    write(fdout, self->output_buff.data, self->output_buff.len);
}
