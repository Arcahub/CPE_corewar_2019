/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** create_core
*/

#include "corewar/corewar.h"
#include "my/collections/vec.h"

bool cw_vm_add_core(cw_vm_t *self, const usize_t pc, u32_t prog_number)
{
    cw_core_t *core = my_malloc(sizeof(cw_core_t));

    if (core == NULL)
        return (true);
    core->regs.pc = pc;
    core->regs.regs[0] = prog_number;
    for (u64_t i = 1; i < 256; i++)
        core->regs.regs[i] = 0;
    core->regs.zero = true;
    core->state.timeout = 0;
    core->state.age = 0;
    if (vec_push(self->cores, core)) {
        my_free(core);
        return (true);
    }
    return (false);
}
