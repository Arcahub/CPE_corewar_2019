/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_vm_new implementation
*/

#include <stddef.h>
#include "my/my.h"
#include "my/io.h"
#include "corewar/corewar.h"

/*
** TODO: Load address default values
*/

static bool load_program(cw_vm_t *self, cw_program_t *prog,
    const cw_program_def_t *def)
{
    usize_t name_len = self->config.prog_name_length;
    usize_t comment_len = self->config.comment_length;
    usize_t name_off = 4;
    usize_t size_off = ((name_off + name_len + 1) / 4 + 1) * 4;
    usize_t comment_off = size_off + 4;
    usize_t data_off = ((comment_off + comment_len + 1) / 4 + 1) * 4;
    u32_t magic = u32_be_to_ne(*((u32_t*) &def->data[0]));
    u32_t prog_size = u32_be_to_ne(*((u32_t*) &def->data[size_off]));

    if (magic != self->config.corewar_exec_magic)
        return (true);
    prog->name = my_cstrdup((const char*) &def->data[name_off]);
    prog_size = *((i32_t*) &prog_size);
    prog->comment = my_cstrdup((const char*) &def->data[comment_off]);
    my_memcpy(&self->mem[def->load_address.v], &def->data[data_off], prog_size);
    return (false);
}

static bool load_programs(cw_vm_t *self, const cw_program_def_t *defs,
    usize_t n)
{
    bool err = false;

    self->prog_count = n;
    self->programs = my_calloc(n, sizeof(cw_program_t));
    for (usize_t i = 0; !err && i < n; i++)
        err = load_program(self, &self->programs[i], &defs[i]);
    return (err);
}

cw_vm_t *cw_vm_new(const cw_config_t *config, const cw_program_def_t *defs,
    usize_t prog_count)
{
    cw_vm_t *self = my_calloc(1, sizeof(cw_vm_t));

    *((cw_config_t*) &self->config) = *config;
    self->cycle_to_die = self->config.cycle_to_die;
    self->mem = my_calloc(self->config.mem_size, sizeof(u8_t));
    self->cores = vec_new();
    self->callbacks.all = list_new();
    for (usize_t i = 0; i < CW_OPCODE_LAST + 1; i++)
        self->callbacks.opcodes[i] = list_new();
    load_programs(self, defs, prog_count);
    return (self);
}
