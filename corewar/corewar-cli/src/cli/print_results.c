/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** print_results
*/

#include "my/my.h"
#include "my/io.h"
#include "corewar/corewar.h"

static void print_draw(cw_vm_t *vm, usize_t last_live, u64_t count)
{
    my_printf("Draw between: ");
    for (u64_t i = 0; i < vm->prog_count; i++) {
        if (vm->programs[i].last_live == last_live) {
            count--;
            my_printf("%d(%s)%s", vm->programs[i].prog_number,
            vm->programs[i].name, count == 0 ? "" : " ");
        }
    }
    my_printf("\n");
}

void cw_corewar_cli_print_winner(cw_vm_t *vm)
{
    u64_t count = 0;
    u64_t prog_number = 0;
    usize_t last_live = 0;
    cw_program_t *prog = &vm->programs[0];

    for (u64_t i = 0; i < vm->prog_count; i++) {
        if (vm->programs[i].last_live > last_live) {
            prog_number = vm->programs[i].prog_number;
            prog = &vm->programs[i];
            last_live = vm->programs[i].last_live;
            count = 1;
        } else if (vm->programs[i].last_live == last_live)
            count += 1;
    }
    if (count > 1)
        print_draw(vm, last_live, count);
    else
        my_printf("The player %d(%s)has won.\n", prog_number,
            prog->name);
}
