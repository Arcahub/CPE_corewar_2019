/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Test the output of special champions written to test a specific instruction
*/

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "corewar/corewar.h"
#include "my/my.h"
#include "my/io.h"
#include "op.h"

static const cw_config_t VM_CONF = {
    .prog_name_length = PROG_NAME_LENGTH,
    .comment_length = COMMENT_LENGTH,
    .corewar_exec_magic = COREWAR_EXEC_MAGIC,
    .reg_size = REG_SIZE,
    .reg_count = REG_NUMBER,
    .idx_mod = IDX_MOD,
    .ind_size = IND_SIZE,
    .dir_size = DIR_SIZE,
    .mem_size = MEM_SIZE,
    .cycle_to_die = CYCLE_TO_DIE,
    .cycle_delta = CYCLE_DELTA,
    .nbr_live = NBR_LIVE,
};

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

static bool handle_aff(void *ptr, cw_vm_t *vm, cw_core_t *core,
    const cw_instr_t *instr)
{
    bufwriter_t *out = ptr;

    (void)(vm);
    bufwriter_putchar(out, core->regs.regs[instr->args[0].u.reg] % 256);
    return (false);
}

static void test_champ(cw_program_def_t *defs, usize_t count)
{
    char *output = NULL;
    bufwriter_t *out = cstrwriter_new(&output, 64);
    cw_vm_t *vm = NULL;

    vm = cw_vm_new(&VM_CONF);
    cw_vm_load_programs(vm, defs, count);
    cr_assert_not_null(vm);
    cw_vm_add_instr_callback(vm, SOME(cw_opcode, CW_INSTR_AFF), &handle_aff,
        out);
    cw_vm_run(vm, NONE(u64));
    cw_vm_destroy(vm);
    bufwriter_free(out);
    cr_assert_str_eq(output, "a");
    my_free(output);
}

Test(test_champs, all_champs)
{
    cw_program_def_t def[2];
    char *path = NULL;
    DIR *dir = opendir("./tests/test_champs");

    load_prog("./tests/champs/tyron.cor", NONE(usize), NONE(u32), &def[1]);
    for (struct dirent *ent = readdir(dir); ent != NULL; ent = readdir(dir)) {
        if (my_cstrstr(ent->d_name, ".cor") == NULL)
            continue;
        path = my_format("./tests/test_champs/%s", ent->d_name);
        load_prog(path, NONE(usize), NONE(u32), &def[0]);
        cr_log_info("Testing \"%s\"", path);
        test_champ(def, 2);
        my_free(path);
    }
    closedir(dir);
}
