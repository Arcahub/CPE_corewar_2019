/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** create_core
*/

#include "corewar/corewar.h"
#include "my/collections/vec.h"

bool cw_vm_add_core(cw_vm_t *self, const usize_t pc, OPT(cw_core) parent)
{
    cw_core_t *core = my_calloc(1, sizeof(cw_core_t));

    if (core == NULL)
        return (true);
    if (parent.is_some)
        *core = parent.v;
    core->regs.pc = pc;
    if (vec_push(self->cores, core)) {
        my_free(core);
        return (true);
    }
    return (false);
}
