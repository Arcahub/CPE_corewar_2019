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

OPT(usize) cw_asm_flush_to_output_buffer(void *user_data, const void *data,
    usize_t count)
{
    cw_asm_output_buff_t *buff = user_data;
    void *new_data = my_malloc(sizeof(u8_t) * (buff->len + count));

    if (!new_data)
        return (NONE(usize));
    my_memcpy(new_data, buff->data, buff->len);
    my_memcpy(new_data + buff->len, data, count);
    buff->len += count;
    my_free(buff->data);
    buff->data = new_data;
    return (SOME(usize, count));
}

bufwriter_t *cw_asm_output_create(cw_asm_output_buff_t *buff)
{
    bufwriter_t *bw = bufwriter_new(512);

    if (bw == NULL)
        return (NULL);
    bw->user_data = buff;
    bw->write_cb = &cw_asm_flush_to_output_buffer;
    return (bw);
}
