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

static bool cw_vm_do_alloc(cw_vm_t *self)
{
    bool err = false;

    self->mem = my_calloc(self->config.mem_size, sizeof(u8_t));
    self->cores = vec_new();
    self->new_cores = vec_new();
    self->callbacks.ops = list_new();
    self->callbacks.io_events = list_new();
    err = !(self->mem && self->cores && self->new_cores &&
        self->callbacks.ops && self->callbacks.io_events);
    for (usize_t i = 0; !err && i < CW_OPCODE_LAST + 1; i++) {
        self->callbacks.opcodes[i] = list_new();
        err |= self->callbacks.opcodes[i] == NULL;
    }
    return (err);
}

cw_vm_t *cw_vm_new(const cw_config_t *config)
{
    cw_vm_t *self = my_calloc(1, sizeof(cw_vm_t));
    bool err = false;

    if (self == NULL || config == NULL) {
        cw_vm_destroy(self);
        return (NULL);
    }
    *((cw_config_t*) &self->config) = *config;
    self->cycle_to_die = self->config.cycle_to_die;
    err = cw_vm_do_alloc(self);
    if (err)
        cw_vm_destroy(self);
    return (err ? NULL : self);
}
