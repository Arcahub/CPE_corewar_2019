/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** VM Constructor tests
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my/my.h"
#include "corewar/corewar.h"

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

static const usize_t DATA_OFFSET = 0x890;

static bool load_prog(const char *path, OPT(usize) load_addr, OPT(u32) prog_num,
    cw_program_def_t *def)
{
    fd_t file = open(path, O_RDONLY);
    u8_t buffer[1024];
    isize_t buffer_len = 0;

    def->load_address = load_addr;
    def->prog_number = prog_num;
    def->data = NULL;
    def->size = 0;
    if (file == -1)
        return (true);
    buffer_len = read(file, buffer, 1024);
    while (buffer_len > 0) {
        def->data = realloc(def->data, def->size + buffer_len);
        memcpy(&def->data[def->size], buffer, buffer_len);
        def->size += buffer_len;
        buffer_len = read(file, buffer, 1024);
    }
    close(file);
    return (false);
}

Test(vm_ctor, no_program)
{
    cw_vm_t *vm = cw_vm_new(&DEFAULT_CONFIG);

    cw_vm_load_programs(vm, NULL, 0);
    cw_vm_destroy(vm);
}

Test(vm_ctor, one_program)
{
    cw_program_def_t def;
    cw_vm_t *vm = NULL;
    bool err = false;

    err = load_prog("tests/champs/tyron.cor", NONE(usize), NONE(u32), &def);
    cr_assert_not(err);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_vm_load_programs(vm, &def, 1);
    cw_vm_destroy(vm);
}

Test(vm_ctor, one_program_load)
{
    cw_program_def_t def;
    cw_vm_t *vm = NULL;

    load_prog("tests/champs/tyron.cor", NONE(usize), NONE(u32), &def);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_vm_load_programs(vm, &def, 1);

    cr_assert_arr_eq(&vm->mem[0], &def.data[DATA_OFFSET],
        def.size - DATA_OFFSET);
    cr_assert_eq(vm->programs[0].prog_number, 1);
    cw_vm_destroy(vm);
}

Test(vm_ctor, one_program_load_wrap)
{
    cw_program_def_t def;
    cw_vm_t *vm = NULL;

    load_prog("tests/champs/tyron.cor", SOME(usize, 6139), NONE(u32), &def);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_vm_load_programs(vm, &def, 1);
    cr_assert_arr_eq(&vm->mem[6139], &def.data[DATA_OFFSET], 4);
    cr_assert_arr_eq(&vm->mem[0], &def.data[DATA_OFFSET + 5],
        def.size - DATA_OFFSET - 4);
    cr_assert_eq(vm->programs[0].prog_number, 1);
    cw_vm_destroy(vm);
}

Test(vm_ctor, two_program)
{
    cw_program_def_t def[2];
    cw_vm_t *vm = NULL;
    bool err = false;

    err = load_prog("tests/champs/tyron.cor", NONE(usize), NONE(u32), &def[0]);
    err |= load_prog("tests/champs/bill.cor", NONE(usize), NONE(u32), &def[1]);
    cr_assert_not(err);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_vm_load_programs(vm, def, 2);
    cw_vm_destroy(vm);
}

Test(vm_ctor, two_program_load)
{
    cw_program_def_t def[2];
    cw_vm_t *vm = NULL;

    load_prog("tests/champs/tyron.cor", NONE(usize), NONE(u32), &def[0]);
    load_prog("tests/champs/bill.cor", NONE(usize), NONE(u32), &def[1]);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_vm_load_programs(vm, def, 2);
    cr_assert_arr_eq(&vm->mem[0], &def[0].data[DATA_OFFSET],
        def[0].size - DATA_OFFSET);
    cr_assert_arr_eq(&vm->mem[vm->config.mem_size / 2],
        &def[1].data[DATA_OFFSET], def[1].size - DATA_OFFSET);
    cr_assert_eq(vm->programs[0].prog_number, 1);
    cr_assert_eq(vm->programs[1].prog_number, 2);
    cw_vm_destroy(vm);
}

Test(vm_ctor, three_program_load)
{
    cw_program_def_t def[3];
    cw_vm_t *vm = NULL;

    load_prog("tests/champs/tyron.cor", NONE(usize), NONE(u32), &def[0]);
    load_prog("tests/champs/bill.cor", NONE(usize), NONE(u32), &def[1]);
    load_prog("tests/champs/42.cor", NONE(usize), NONE(u32), &def[2]);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_vm_load_programs(vm, def, 3);
    cr_assert_arr_eq(&vm->mem[0], &def[0].data[DATA_OFFSET],
        def[0].size - DATA_OFFSET);
    cr_assert_arr_eq(&vm->mem[vm->config.mem_size / 3],
        &def[1].data[DATA_OFFSET], def[1].size - DATA_OFFSET);
    cr_assert_arr_eq(&vm->mem[vm->config.mem_size / 3 * 2],
        &def[2].data[DATA_OFFSET], def[2].size - DATA_OFFSET);
    cr_assert_eq(vm->programs[0].prog_number, 1);
    cr_assert_eq(vm->programs[1].prog_number, 2);
    cr_assert_eq(vm->programs[2].prog_number, 3);
    cw_vm_destroy(vm);
}

Test(vm_ctor, three_program_load_addr)
{
    cw_program_def_t def[3];
    cw_vm_t *vm = NULL;

    load_prog("tests/champs/tyron.cor", NONE(usize), NONE(u32), &def[0]);
    load_prog("tests/champs/bill.cor", NONE(usize), NONE(u32), &def[1]);
    load_prog("tests/champs/42.cor", SOME(usize, 621), NONE(u32), &def[2]);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cw_vm_load_programs(vm, def, 3);
    cr_assert_arr_eq(&vm->mem[0], &def[0].data[DATA_OFFSET],
        def[0].size - DATA_OFFSET);
    cr_assert_arr_eq(&vm->mem[vm->config.mem_size / 3],
        &def[1].data[DATA_OFFSET], def[1].size - DATA_OFFSET);
    cr_assert_arr_eq(&vm->mem[621],
        &def[2].data[DATA_OFFSET], def[2].size - DATA_OFFSET);
    cr_assert_eq(vm->programs[0].prog_number, 1);
    cr_assert_eq(vm->programs[1].prog_number, 2);
    cr_assert_eq(vm->programs[2].prog_number, 3);
    cw_vm_destroy(vm);
}

Test(vm_ctor, overlap)
{
    cw_program_def_t def[2];
    cw_vm_t *vm = NULL;

    load_prog("tests/champs/tyron.cor", SOME(usize, 1), NONE(u32), &def[0]);
    load_prog("tests/champs/bill.cor", SOME(usize, 1), NONE(u32), &def[1]);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cr_assert_eq(cw_vm_load_programs(vm, def, 2), 1);
}

Test(vm_ctor, invalid_size)
{
    cw_program_def_t def[1];
    cw_vm_t *vm = NULL;

    load_prog("tests/champs/invalid_size.cor", SOME(usize, 1), NONE(u32),
        &def[0]);
    vm = cw_vm_new(&DEFAULT_CONFIG);
    cr_assert_eq( cw_vm_load_programs(vm, def, 1), true);
    cw_vm_destroy(vm);
}
