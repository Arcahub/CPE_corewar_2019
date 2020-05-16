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
    } else if (list_push_front(self->callbacks.ops, callback)) {
        my_free(callback);
        return (true);
    }
    return (false);
}

bool cw_vm_remove_instr_callback(cw_vm_t *self, OPT(cw_opcode) opcode_filter,
    cw_instr_callback_fn_t *fn)
{
    list_t *callback_list = NULL;

    if (opcode_filter.is_some) {
        if (opcode_filter.v > 0 && opcode_filter.v <= CW_INSTR_AFF)
            return (true);
        callback_list = self->callbacks.opcodes[opcode_filter.v];
    } else
        callback_list = self->callbacks.ops;
    LIST_FOR_EACH(callback_list, iter) {
        if (((cw_instr_callback_t*) iter.v)->fn == fn) {
            list_remove(callback_list, iter.i);
            my_free(iter.v);
            break;
        }
    }
    return (false);
}

bool cw_vm__trigger_callbacks_ops(cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr)
{
    bool err = false;
    cw_instr_callback_t *cb = NULL;

    LIST_FOR_EACH_AND(vm->callbacks.ops, iter, !err) {
        cb = iter.v;
        err = cb->fn(cb->data, vm, core, instr);
    }
    LIST_FOR_EACH_AND(vm->callbacks.opcodes[instr->opcode], iter, !err) {
        cb = iter.v;
        err = cb->fn(cb->data, vm, core, instr);
    }
    return (err);
}
