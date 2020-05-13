/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** update
*/

#include "corewar/corewar.h"
#include "my/my.h"

OPT(i64) cw_vm_update_core(void *user_data, void *element)
{
    cw_vm_t *self = user_data;
    cw_core_t *core = element;

    if (core->state.timeout == 0)
        fectch(); // fetch
    else {
        if (core->cache.instruct.is_some)
            exec(); // exec
        else
            core->regs.pc++;
    }
    core->state.age++;
    if (core->state.age == self->cycle_to_die)
        vec_remove_element(self->cores, element, NULL); //kill (need function to free regs);
    return (NONE(i64));
}

bool cw_vm_update(cw_vm_t *self)
{
    self->age++;
    vec_for_each(self->cores, &cw_vm_update_core, self);
    if (self->age == self->config.cycle_to_die) {
        self->age = 0;
        self->cycle_to_die -= u64_min(self->cycle_to_die,
        self->config.cycle_delta);
    }
    if (self->cycle_to_die == 0)
        return (true);
    return (false);
}
