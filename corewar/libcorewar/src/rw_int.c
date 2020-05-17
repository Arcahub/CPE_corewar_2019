/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** VM IO utils
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "priv.h"

i64_t cw_vm__read_int_with_callbacks(const cw_vm_t *vm, i64_t addr, usize_t n,
    const cw_core_t *core)
{
    bool sign = vm->mem[cw_vm_compute_addr(vm, addr)] & 0x80;
    union {
        i64_t i64;
        u8_t bytes[8];
    } val = { .i64 = sign ? -1 : 0 };

    for (usize_t i = 0; i < n; i++)
        val.bytes[8 - n + i] = vm->mem[cw_vm_compute_addr(vm, (addr + i))];
    val.i64 = u64_be_to_ne(val.i64);
    cw_vm__trigger_callbacks_io_read(vm, core, addr, n);
    return (val.i64);
}

i64_t cw_vm__read_int(const cw_vm_t *vm, i64_t addr, usize_t n)
{
    bool sign = vm->mem[cw_vm_compute_addr(vm, addr)] & 0x80;
    union {
        i64_t i64;
        u8_t bytes[8];
    } val = { .i64 = sign ? -1 : 0 };

    for (usize_t i = 0; i < n; i++)
        val.bytes[8 - n + i] = vm->mem[cw_vm_compute_addr(vm, (addr + i))];
    val.i64 = u64_be_to_ne(val.i64);
    return (val.i64);
}

void cw_vm__write_int(cw_vm_t *vm, i64_t val, i64_t addr, usize_t n,
    cw_core_t *core)
{
    union {
        i64_t i64;
        u8_t bytes[8];
    } u;

    u.i64 = u64_ne_to_be(val);
    for (usize_t i = 0; i < n; i++) {
        vm->mem[cw_vm_compute_addr(vm, (addr + i))] = u.bytes[8 - n + i];
    }
    cw_vm__trigger_callbacks_io_write(vm, core, addr, n);
}
