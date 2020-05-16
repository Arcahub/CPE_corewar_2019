/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** callback
*/

#include "corewar/corewar.h"
#include "my/my.h"

bool cw_vm_add_io_event_callback(cw_vm_t *self, cw_io_event_type_t type,
    cw_io_event_callback_fn_t *fn, void*user_data)
{
    cw_io_event_callback_t *callback = my_calloc(1,
        sizeof(cw_io_event_callback_t));

    if (!callback || !fn) {
        my_free(callback);
        return (true);
    }
    callback->fn = fn;
    callback->data = user_data;
    callback->type = type;
    if (list_push_front(self->callbacks.io_events, callback)) {
        my_free(callback);
        return (true);
    }
    return (false);
}

bool cw_vm_remove_instr_callback(cw_vm_t *self, cw_instr_callback_fn_t *fn)
{
    list_t *callback_list = self->callbacks.io_events;

    LIST_FOR_EACH(callback_list, iter) {
        if (((cw_instr_callback_t*) iter.v)->fn == fn) {
            list_remove(callback_list, iter.i);
            my_free(iter.v);
            break;
        }
    }
    return (false);
}

bool cw_vm__trigger_callbacks_io_write(cw_vm_t *vm, cw_core_t *core,
    usize_t addr, usize_t size)
{
    bool err = false;
    cw_io_event_callback_t *cb = NULL;
    cw_io_event_t event = {size, addr};

    LIST_FOR_EACH_AND(vm->callbacks.io_events, iter, !err) {
        cb = iter.v;
        err = cb->fn(vm, cb->data, core, event);
    }
    return (err);
}


bool cw_vm__trigger_callbacks_io_read(cw_vm_t *vm, cw_core_t *core,
    usize_t addr, usize_t size)
{
    bool err = false;
    cw_io_event_callback_t *cb = NULL;
    cw_io_event_t event = {size, addr};

    LIST_FOR_EACH_AND(vm->callbacks.io_events, iter, !err) {
        cb = iter.v;
        err = cb->fn(vm, cb->data, core, event);
    }
    return (err);
}
