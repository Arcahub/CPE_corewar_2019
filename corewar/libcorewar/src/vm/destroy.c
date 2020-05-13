/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** VM destroyer
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "corewar/corewar.h"

void cw_vm_destroy_program(cw_program_t *prog)
{
    my_free(prog->name);
    my_free(prog->comment);
}

void cw_vm_destroy_core(cw_core_t *core)
{
    my_free(core);
}

static OPT(i32) destroy_callback(void *ptr, void *element)
{
    (void)(ptr);
    my_free(element);
    return (NONE(i32));
}

void cw_vm_destroy(cw_vm_t *self)
{
    if (self == NULL)
        return;
    my_free(self->mem);
    for (usize_t i = 0; self->programs && i < self->prog_count; i++)
        cw_vm_destroy_program(&self->programs[i]);
    my_free(self->programs);
    for (usize_t i = 0; self->cores && i < self->cores->len; i++)
        cw_vm_destroy_core(self->cores->data[i]);
    vec_destroy(self->cores);
    list_destroy_with(self->callbacks.all, &destroy_callback, NULL);
    for (usize_t i = 0; i < CW_OPCODE_LAST + 1; i++)
        list_destroy_with(self->callbacks.opcodes[i], &destroy_callback, NULL);
    my_free(self);
}
