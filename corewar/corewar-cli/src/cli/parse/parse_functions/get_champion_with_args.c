/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_champion
*/

#include "corewar-cli/corewar.h"
#include "corewar-cli/corewar-cli.h"
#include "my/io.h"
#include "../priv.h"

static u64_t cw_corewar_cli_get_load_address(char **argv,
usize_t *index, my_opt__usize_t *load_address)
{
    for (u64_t i = *index; i < 4 && argv[i] != NULL; i++) {
        if (my_cstreq(argv[i], "-a") &&
        (argv[i + 1] == NULL || !my_cstr_isnum(argv[i + 1]))) {
            my_printf("Invalid argument after -a\n");
            return (84);
        } else if (my_cstreq(argv[i], "-a")) {
            *load_address = SOME(usize, my_cstr_getnbr(argv[i + 1]));
            return (1);
        }
    }
    return (0);
}

static u64_t cw_corewar_cli_get_prog_number(char **argv,
usize_t *index, my_opt__u32_t *prog_number)
{
    for (u64_t i = *index; i < 4 && argv[i] != NULL; i++) {
        if (my_cstreq(argv[i], "-n") &&
        (argv[i + 1] == NULL || !my_cstr_isnum(argv[i + 1]))) {
            my_printf("Invalid argument after -n\n");
            return (84);
        } else if (my_cstreq(argv[i], "-n")) {
            *prog_number = SOME(u32, my_cstr_getnbr(argv[i + 1]));
            return (1);
        }
    }
    return (0);
}

bool cw_corewar_cli_get_champion_with_args(char **argv, usize_t *index, void *data)
{
    u64_t index_offset = 0;
    u64_t exit_status = 0;
    my_opt__usize_t load_address = NONE(usize);
    my_opt__u32_t prog_number = NONE(u32);

    exit_status = cw_corewar_cli_get_load_address(argv, index, &load_address);
    if (exit_status == 84)
        return (false);
    index_offset = (exit_status == 1) ? index_offset + 2 : index_offset;
    exit_status = cw_corewar_cli_get_prog_number(argv, index, &prog_number);
    if (exit_status == 84)
        return (false);
    index_offset = (exit_status == 1) ? index_offset + 2 : index_offset;
    *index += index_offset;
    if (argv[*index] == NULL) {
        my_printf("Champion Name is missing\n");
        return (false);
    }
    return (cw_corewar_cli_add_prog(data, prog_number, load_address,
    argv[*index]));
}