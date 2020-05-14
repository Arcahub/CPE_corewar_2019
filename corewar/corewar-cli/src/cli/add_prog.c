/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add_prog
*/

#include "corewar-cli/corewar-cli.h"
#include "my/io.h"
#include <stdlib.h>
#include <fcntl.h>

bool cw_corewar_cli_add_prog(cw_corewar_cli_t *self, OPT(u32) prog_number,
    OPT(usize) load_address, const char *filepath)
{
    cw_program_def_t *prog = my_malloc(sizeof(cw_program_def_t));
    bufreader_t *bf = filereader_open(filepath, 1);

    if (!prog || !bf) {
        my_free(prog);
        bufreader_free(bf);
        my_printf("Can't open champ: %s\n", filepath);
        return (false);
    }
    prog->prog_number = (prog_number.is_some) ? prog_number : NONE(u32);
    prog->load_address = (load_address.is_some) ? load_address : NONE(usize);
    prog->size = 0;
    prog->data = NULL;
    for (OPT(u8) tmp = bufreader_read_u8(bf); tmp.is_some;
    tmp = bufreader_read_u8(bf)) {
        prog->data = realloc(prog->data, prog->size + 1);
        my_memcpy(prog->data + prog->size, &tmp.v, 1);
        prog->size += 1;
    }
    bufreader_free(bf);
    return (list_push_front(self->progs_list, prog));
}
