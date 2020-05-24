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

static const char *OPCODE_NAMES[] = {
    NULL,
    "live",
    "ld",
    "st",
    "add",
    "sub",
    "and",
    "or",
    "xor",
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lld",
    "lldi",
    "lfork",
    "aff",
};

static bool log_instr1(void *user_data, cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr)
{
    (void)(user_data);
    (void)(vm);
    (void)(core);
    printf("1 %s;", OPCODE_NAMES[instr->opcode]);
    fflush(stdout);
    return (false);
}

static bool log_instr2(void *user_data, cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr)
{
    (void)(user_data);
    (void)(vm);
    (void)(core);
    printf("2 %s;", OPCODE_NAMES[instr->opcode]);
    fflush(stdout);
    return (false);
}

TestSuite(calllbacks_ops, .timeout = 1, .init = cr_redirect_stdout);

Test(calllbacks_ops, add_one_callbacks)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err = cw_vm_add_instr_callback(vm, NONE(cw_opcode), &log_instr1, NULL);
    cr_assert(!err);
    cw_vm_destroy(vm);
}

Test(calllbacks_ops, add_some_callbacks)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    err |= cw_vm_add_instr_callback(vm, NONE(cw_opcode), &log_instr1, NULL);
    err |= cw_vm_add_instr_callback(vm, SOME(cw_opcode, CW_INSTR_ADD),
        &log_instr1, NULL);
    err |= cw_vm_add_instr_callback(vm, SOME(cw_opcode, CW_INSTR_AFF),
        &log_instr1, NULL);
    err |= cw_vm_add_instr_callback(vm, NONE(cw_opcode), &log_instr2, NULL);
    err |= cw_vm_add_instr_callback(vm, SOME(cw_opcode, CW_INSTR_LLD),
        &log_instr1, NULL);
    cr_assert(!err);
    cw_vm_destroy(vm);
}

Test(calllbacks_ops, trigger_one_callback)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_instr_t instr = {0};
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    instr.opcode = CW_INSTR_STI;
    cw_vm_add_instr_callback(vm, NONE(cw_opcode), &log_instr1, NULL);
    err |= cw_vm__trigger_callbacks_ops(vm, NULL, &instr);
    instr.opcode = CW_INSTR_AFF;
    err |= cw_vm__trigger_callbacks_ops(vm, NULL, &instr);
    instr.opcode = CW_INSTR_LIVE;
    err |= cw_vm__trigger_callbacks_ops(vm, NULL, &instr);
    cr_assert(!err);
    cw_vm_destroy(vm);
    cr_assert_stdout_eq_str("1 sti;1 aff;1 live;");
}

Test(calllbacks_ops, trigger_filtered_callbacks)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_instr_t instr = {0};
    bool err = false;

    cw_vm_load_programs(vm, NULL, 0);
    instr.opcode = CW_INSTR_STI;
    cw_vm_add_instr_callback(vm, NONE(cw_opcode), &log_instr1, NULL);
    cw_vm_add_instr_callback(vm, SOME(cw_opcode, CW_INSTR_ADD), &log_instr1,
        NULL);
    cw_vm_add_instr_callback(vm, SOME(cw_opcode, CW_INSTR_AFF), &log_instr2,
        NULL);
    cw_vm_add_instr_callback(vm, SOME(cw_opcode, CW_INSTR_LLD), &log_instr1,
        NULL);
    err |= cw_vm__trigger_callbacks_ops(vm, NULL, &instr);
    instr.opcode = CW_INSTR_AFF;
    err |= cw_vm__trigger_callbacks_ops(vm, NULL, &instr);
    instr.opcode = CW_INSTR_ADD;
    err |= cw_vm__trigger_callbacks_ops(vm, NULL, &instr);
    cr_assert(!err);
    cw_vm_destroy(vm);
    cr_assert_stdout_eq_str("1 sti;1 aff;2 aff;1 add;1 add;");
}
