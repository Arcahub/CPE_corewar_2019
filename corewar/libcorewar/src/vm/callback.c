/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** callback
*/

#include "corewar/corewar.h"
#include "my/my.h"

bool cw_vm_add_instr_callback(cw_vm_t *self, OPT(cw_opcode) opcode_filter,
    cw_instr_callback_fn_t *fn, void *user_data)
{
    cw_instr_callback_t *callback = my_calloc(1, sizeof(cw_instr_callback_t));

    if (!callback || !fn) {
        my_free(callback);
        return (true);
    }
    callback->fn = fn;
    callback->data = user_data;
    if (opcode_filter.is_some) {
        if (opcode_filter.v == 0 || opcode_filter.v > CW_INSTR_AFF ||
            list_push_front(self->callbacks.opcodes[opcode_filter.v],
            callback)) {
            my_free(callback);
            return (true);
        }
    } else if (list_push_front(self->callbacks.all, callback)) {
        my_free(callback);
        return (true);
    }
    return (false);
}

bool (list_find_fn_t)(void *user_data, void *element);
static bool find_callback(void *user_data, void *element)
{
    cw_instr_callback_fn_t *fn = user_data;
    cw_instr_callback_t *callback = element;

    if (callback->fn == fn)
        return (true);
    return (false);
}

bool cw_vm_remove_instr_callback(cw_vm_t *self, OPT(cw_opcode) opcode_filter,
    cw_instr_callback_fn_t *fn)
{
    cw_instr_callback_t *callback = NULL;
    usize_t index = 0;
    list_t *callback_list = NULL;

    if (opcode_filter.is_some) {
        if (opcode_filter.v > 0 && opcode_filter.v <= CW_INSTR_AFF)
            return (true);
        callback_list = self->callbacks.opcodes[opcode_filter.v];
    } else
        callback_list = self->callbacks.all;
    list_remove_element(callback_list, fn, &find_callback);
    return (false);
}
