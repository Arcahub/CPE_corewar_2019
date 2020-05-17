/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Callback tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my/my.h"
#include "corewar/corewar.h"
#include "../src/priv.h"

static const cw_config_t DEFAULT_CONFIG = {
    .prog_name_length = 128,
    .comment_length = 2048,
    .corewar_exec_magic = 0xEA83F3,
    .reg_size = 4,
    .reg_count = 16,
    .idx_mod = 512,
    .ind_size = 2,
    .dir_size = 4,
    .mem_size = 6 * 1024,
    .cycle_to_die = 1536,
    .cycle_delta = 5,
    .nbr_live = 40,
};

static bool log_instr1(const cw_vm_t *vm, void *user_data,
    const cw_core_t *core, const cw_io_event_t *event)
{
    (void)(user_data);
    (void)(vm);
    (void)(core);
    printf("1 %d;", event->addr);
    fflush(stdout);
    return (false);
}

static bool log_instr2(const cw_vm_t *vm, void *user_data,
    const cw_core_t *core, const cw_io_event_t *event)
{
    (void)(user_data);
    (void)(vm);
    (void)(core);
    printf("2 %d;", event->addr);
    fflush(stdout);
    return (false);
}

TestSuite(calllbacks_io_events, .timeout = 1, .init = cr_redirect_stdout);

Test(calllbacks_io_events, add_write_callback)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err = cw_vm_add_io_event_callback(vm, CW_IO_WRITE, &log_instr1, NULL);
    cr_assert(!err);
    cw_vm_destroy(vm);
}

Test(calllbacks_io_events, add_read_callback)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err = cw_vm_add_io_event_callback(vm, CW_IO_READ, &log_instr1, NULL);
    cr_assert(!err);
    cw_vm_destroy(vm);
}

Test(calllbacks_io_events, add_both_callbacks)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_WRITE, &log_instr1, NULL);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_READ, &log_instr1, NULL);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_WRITE, &log_instr2, NULL);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_READ, &log_instr2, NULL);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_READ, &log_instr1, NULL);
    cr_assert(!err);
    cw_vm_destroy(vm);
}

Test(calllbacks_io_events, trigger_one_callback_read)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_READ, &log_instr1, NULL);
    err |= cw_vm__trigger_callbacks_io_read(vm, NULL, 10, 0);
    err |= cw_vm__trigger_callbacks_io_write(vm, NULL, 15, 0);
    err |= cw_vm__trigger_callbacks_io_read(vm, NULL, 20, 0);
    cr_assert(!err);
    cw_vm_destroy(vm);
    cr_assert_stdout_eq_str("1 10;1 20;");
}

Test(calllbacks_io_events, trigger_one_callback_write)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_WRITE, &log_instr2, NULL);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_READ, &log_instr1, NULL);
    err |= cw_vm__trigger_callbacks_io_write(vm, NULL, 5, 0);
    err |= cw_vm__trigger_callbacks_io_read(vm, NULL, 10, 0);
    err |= cw_vm__trigger_callbacks_io_write(vm, NULL, 15, 0);
    err |= cw_vm__trigger_callbacks_io_read(vm, NULL, 20, 0);
    err |= cw_vm__trigger_callbacks_io_write(vm, NULL, 25, 0);
    err |= cw_vm__trigger_callbacks_io_read(vm, NULL, 30, 0);
    cr_assert(!err);
    cw_vm_destroy(vm);
    cr_assert_stdout_eq_str("2 5;1 10;2 15;1 20;2 25;1 30;");
}

Test(calllbacks_io_events, trigger_filtered_callbacks)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err |= cw_vm_add_io_event_callback(vm, CW_IO_WRITE, &log_instr2, NULL);
    err |= cw_vm__trigger_callbacks_io_write(vm, NULL, 5, 0);
    err |= cw_vm__trigger_callbacks_io_read(vm, NULL, 10, 0);
    err |= cw_vm__trigger_callbacks_io_write(vm, NULL, 15, 0);
    cr_assert(!err);
    cw_vm_destroy(vm);
    cr_assert_stdout_eq_str("2 5;2 15;");
}
