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
#include "../priv.h"
#include "priv.h"

static u32_t next_program_number(const cw_vm_t *self)
{
    u32_t prog_num = 0;
    bool valid = true;

    do {
        valid = true;
        for (usize_t i = 0; valid && i < self->prog_count; i++) {
            valid &= prog_num != self->programs[i].prog_number;
        }
        prog_num += valid ? 0 : 1;
    } while (!valid);
    return (prog_num);
}

static bool load_prog(cw_vm_t *self, cw_program_t *prog,
    const cw_program_def_t *def, usize_t size_off)
{
    usize_t comment_len = self->config.comment_length;
    usize_t comment_off = size_off + 4;
    usize_t data_off = ((comment_off + comment_len + 1) / 4 + 1) * 4;
    usize_t start = def->load_address.v;
    u32_t prog_size = u32_be_to_ne(*((u32_t*) &def->data[size_off]));
    usize_t cut = usize_min(start + prog_size, self->config.mem_size);
    usize_t remaining = prog_size - (cut - start);

    *((u32_t*) &prog->prog_number) = def->prog_number.is_some ?
        def->prog_number.v % self->config.mem_size : next_program_number(self);
    for (usize_t i = start; i < prog_size; i++)
        if (self->mem[i % self->config.mem_size] != 0)
            return (true);
    my_memcpy(&self->mem[start], &def->data[data_off], cut - start);
    my_memcpy(&self->mem[0], &def->data[data_off + cut - start], remaining);
    return (false);
}

static bool create_program(cw_vm_t *self, cw_program_t *prog,
    const cw_program_def_t *def)
{
    usize_t name_len = self->config.prog_name_length;
    usize_t name_off = 4;
    usize_t size_off = ((name_off + name_len + 1) / 4 + 1) * 4;
    usize_t comment_off = size_off + 4;
    u32_t magic = u32_be_to_ne(*((u32_t*) &def->data[0]));
    usize_t pc = def->load_address.v % self->config.mem_size;

    if (magic != self->config.corewar_exec_magic)
        return (true);
    prog->name = my_cstrdup((const char*) &def->data[name_off]);
    prog->comment = my_cstrdup((const char*) &def->data[comment_off]);
    if (!prog->name || !prog->comment || load_prog(self, prog, def, size_off) ||
        cw_vm_add_core(self, pc, prog->prog_number)) {
        cw_vm_destroy_program(prog);
        return (true);
    }
    ((cw_core_t *) vec_get(self->cores, 0).v)->regs.regs[0] = 0;
    return (false);
}

static bool load_programs(cw_vm_t *self, const cw_program_def_t *defs,
    usize_t n)
{
    bool err = false;
    cw_program_def_t def;

    self->prog_count = 0;
    self->programs = my_calloc(n, sizeof(cw_program_t));
    err = self->programs == NULL;
    for (usize_t i = 0; !err && i < n; i++) {
        def = defs[i];
        if (cw_vm_check_prog(self, &def))
            return (true);
        if (!defs[i].load_address.is_some)
            def.load_address = SOME(usize, i * self->config.mem_size / n);
        err = create_program(self, &self->programs[i], &def);
        self->prog_count += err ? 0 : 1;
    }
    return (err);
}

cw_vm_t *cw_vm_new(const cw_config_t *config, const cw_program_def_t *defs,
    usize_t prog_count)
{
    cw_vm_t *self = my_calloc(1, sizeof(cw_vm_t));
    bool err = false;

    if (self == NULL)
        return (NULL);
    *((cw_config_t*) &self->config) = *config;
    self->cycle_to_die = self->config.cycle_to_die;
    self->mem = my_calloc(self->config.mem_size, sizeof(u8_t));
    self->cores = vec_new();
    self->new_cores = vec_new();
    self->callbacks.all = list_new();
    err = !(self->mem && self->cores && self->new_cores && self->callbacks.all);
    for (usize_t i = 0; !err && i < CW_OPCODE_LAST + 1; i++) {
        self->callbacks.opcodes[i] = list_new();
        err |= self->callbacks.opcodes[i] == NULL;
    }
    err = err || load_programs(self, defs, prog_count);
    if (err)
        cw_vm_destroy(self);
    return (err ? NULL : self);
}
