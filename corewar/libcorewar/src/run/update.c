/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** update
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "../priv.h"
#include "priv.h"

static const usize_t INSTR_TIMEOUT[256] = {
    0, 10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2,
};

static void update_core(cw_vm_t *self, cw_core_t *core)
{
    core->state.age++;
    core->state.timeout--;
    if (core->state.timeout > 0)
        return;
    if (core->cache.instruct.is_some) {
        cw_vm__exec_instr(self, core, &core->cache.instruct.v);
        core->regs.pc = core->cache.instruct.v.end;
    } else
        core->regs.pc++;
    core->state.timeout = 1;
    core->cache.instruct = NONE(cw_instr);
    if (!cw_vm__fetch_instr(self, core, &core->cache.instruct.v)) {
        core->cache.instruct.is_some = true;
        core->state.timeout = INSTR_TIMEOUT[core->cache.instruct.v.opcode];
    }
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
