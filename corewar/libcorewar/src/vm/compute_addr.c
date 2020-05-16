/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** compute_addr
*/

#include "corewar/corewar.h"

isize_t cw_vm_compute_addr(const cw_vm_t *vm, isize_t addr)
{
    if (addr >= 0)
        addr = addr % (isize_t) vm->config.mem_size;
    else {
        addr = addr % (isize_t) vm->config.mem_size;
        addr = (isize_t) vm->config.mem_size + addr;
    }
    return (addr);
}
