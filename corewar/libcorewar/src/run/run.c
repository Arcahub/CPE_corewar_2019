/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** run
*/

#include "corewar/corewar.h"

bool cw_vm_run(cw_vm_t *self, OPT(u64) cycle_count)
{
    bool vm_ended = false;

    if (!cycle_count.is_some) {
        while (!cw_vm_update(self));
        return (true);
    }
    for (u64_t i = 0; !vm_ended && i < cycle_count.v; i++) {
        vm_ended = cw_vm_update(self);
    }
    return (vm_ended);
}
