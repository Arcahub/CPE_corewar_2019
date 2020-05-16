/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** dump
*/

#include <stdlib.h>
#include "corewar/corewar.h"
#include "my/fmt.h"
#include "my/io.h"

static void display_row(cw_vm_t *vm, usize_t start_address, usize_t max_add_len)
{
    my_printf("%-*x :", max_add_len, start_address);
    for (size_t i = 0; i < 0x20; i++) {
        if (start_address + i >= vm->config.mem_size)
            break;
        my_printf(" %02x", vm->mem[start_address + i]);
    }
    my_putcstr("\n");
}

void cw_corewar_cli_dump(cw_vm_t *vm)
{
    char *max_mem_size = my_format("%x", vm->config.mem_size);
    usize_t max_add_len = my_cstrlen(max_mem_size);
    uint32_t rows = vm->config.mem_size / 0x20 +
        (vm->config.mem_size % 0x20 == 0 ? 0 : 1);

    free(max_mem_size);
    for (size_t i = 0; i < rows; i++)
        display_row(vm, i * 0x20, max_add_len);
}
