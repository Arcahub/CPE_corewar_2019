/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** update
*/

#include "corewar/corewar.h"
#include "my/my.h"

static void update_core(cw_vm_t *self, cw_core_t *core)
{
    (void)(self);
    if (core->state.timeout == 0)
        /* TODO: fetch here */;
    else {
        if (core->cache.instruct.is_some)
            /* TODO: exec here */;
        else
            core->regs.pc++;
    }
    core->state.age++;
}

static void do_check(cw_vm_t *self)
{
    cw_core_t *core = NULL;

    for (usize_t i = 0; i < self->cores->len; i++) {
        core = self->cores->data[i];
        if (core->state.age >= self->cycle_to_die) {
            vec_remove(self->cores, i);
            i--;
        }
    }
    if (self->state.live_calls >= self->config.nbr_live ||
        self->state.checks_passed >= self->config.max_checks) {
        self->cycle_to_die -= u64_min(self->cycle_to_die,
            self->config.cycle_delta);
        self->state.checks_passed = 0;
    } else
        self->state.checks_passed++;
    self->state.live_calls = 0;
}

bool cw_vm_update(cw_vm_t *self)
{
    for (usize_t i = 0; i < self->cores->len; i++)
        update_core(self, self->cores->data[i]);
    self->state.check_countdown--;
    if (self->state.check_countdown == 0) {
        do_check(self);
        self->state.check_countdown = self->cycle_to_die;
    }
    if (self->cycle_to_die == 0)
        return (true);
    return (false);
}
