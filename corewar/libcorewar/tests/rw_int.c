/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Tests for int reads and writes
*/

#include <criterion/criterion.h>
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

static const u8_t DEFAULT_DATA[] = {
    0x00, 0x00, 0x00, 0x7b,
    0xff, 0xff, 0xff, 0xf4,
};

Test(read_int, positives)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG, NULL, 0);

    my_memcpy(vm->mem, DEFAULT_DATA, sizeof(DEFAULT_DATA) / sizeof(u8_t));
    cr_assert_eq(cw_vm__read_int(vm, 0, 4), 123);
    cr_assert_eq(cw_vm__read_int(vm, 1, 3), 123);
    cr_assert_eq(cw_vm__read_int(vm, 2, 2), 123);
    cr_assert_eq(cw_vm__read_int(vm, 3, 1), 123);
}

Test(read_int, negatives)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG, NULL, 0);

    my_memcpy(vm->mem, DEFAULT_DATA, sizeof(DEFAULT_DATA) / sizeof(u8_t));
    cr_assert_eq(cw_vm__read_int(vm, 4, 4), -12);
    cr_assert_eq(cw_vm__read_int(vm, 5, 3), -12);
    cr_assert_eq(cw_vm__read_int(vm, 6, 2), -12);
    cr_assert_eq(cw_vm__read_int(vm, 7, 1), -12);
}

Test(write_int, positives)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG, NULL, 0);

    cw_vm__write_int(vm, 123, 0, 4);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0x00, 0x00, 0x00, 0x7b}), 4);
    my_memset(vm->mem, 0, 16);
    cw_vm__write_int(vm, 123, 1, 3);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0x00, 0x00, 0x00, 0x7b}), 4);
    my_memset(vm->mem, 0, 16);
    cw_vm__write_int(vm, 123, 2, 2);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0x00, 0x00, 0x00, 0x7b}), 4);
    my_memset(vm->mem, 0, 16);
    cw_vm__write_int(vm, 123, 3, 1);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0x00, 0x00, 0x00, 0x7b}), 4);
    my_memset(vm->mem, 0, 16);
}

Test(write_int, negatives)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG, NULL, 0);

    cw_vm__write_int(vm, -12, 0, 4);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0xff, 0xff, 0xff, 0xf4}), 4);
    my_memset(vm->mem, 0, 16);
    cw_vm__write_int(vm, -12, 1, 3);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0x00, 0xff, 0xff, 0xf4}), 4);
    my_memset(vm->mem, 0, 16);
    cw_vm__write_int(vm, -12, 2, 2);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0x00, 0x00, 0xff, 0xf4}), 4);
    my_memset(vm->mem, 0, 16);
    cw_vm__write_int(vm, -12, 3, 1);
    cr_assert_arr_eq(vm->mem, ((u8_t[]) {0x00, 0x00, 0x00, 0xf4}), 4);
}
