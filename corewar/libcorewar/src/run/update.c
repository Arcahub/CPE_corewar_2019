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
    core->state.timeout = core->state.timeout == 0 ?
        core->state.timeout : core->state.timeout - 1;
    if (core->state.timeout > 0)
        return;
    if (core->cache.instruct.is_some) {
        cw_vm__exec_instr(self, core, &core->cache.instruct.v);
    }
    core->state.timeout = 1;
    core->cache.instruct = NONE(cw_instr);
    if (!cw_vm__fetch_instr(self, core, &core->cache.instruct.v)) {
        core->cache.instruct.is_some = true;
        core->state.timeout = INSTR_TIMEOUT[core->cache.instruct.v.opcode];
    } else
        core->regs.pc++;
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
}

static void merge_core(cw_vm_t *self, cw_core_t *core)
{
    core->state.timeout = 1;
    core->cache.instruct = NONE(cw_instr);
    vec_push(self->cores, core);
}

bool cw_vm__update(cw_vm_t *self)
{
    self->state.cycles += 1;
    for (usize_t i = 0; i < self->cores->len; i++)
        update_core(self, self->cores->data[i]);
    while (self->new_cores->len > 0)
        merge_core(self, vec_pop(self->new_cores).v);
    self->state.cycles_since_check++;
    if (self->state.cycles_since_check >= self->cycle_to_die) {
        do_check(self);
        self->state.cycles_since_check = 0;
    }
    if (self->cycle_to_die == 0 || self->cores->len < 2)
        return (true);
    return (false);
}
