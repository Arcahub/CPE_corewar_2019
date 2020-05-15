/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** VM IO utils
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "priv.h"

i64_t cw_vm__read_int(const cw_vm_t *vm, i64_t addr, usize_t n)
{
    union {
        i64_t i64;
        u8_t bytes[8];
    } val = {0};

    for (usize_t i = 0; i < n; i++)
        val.bytes[i] = vm->mem[(addr + i) % vm->config.mem_size];
    return (u64_be_to_ne(val.i64) >> (64 - 8 * n));
}

void cw_vm__write_int(cw_vm_t *vm, i64_t val, i64_t addr, usize_t n)
{
    union {
        i64_t i64;
        u8_t bytes[8];
    } u;

    u.i64 = u64_ne_to_be(val << (64 - 8 * n));
    for (usize_t i = 0; i < n; i++)
        vm->mem[(addr + i) % vm->config.mem_size] = u.bytes[i];
}
