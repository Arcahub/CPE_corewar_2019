/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** reverser_bytes
*/

#include <stdint.h>

uint32_t reverse_bytes(uint32_t bytes)
{
    uint32_t aux = 0;
    uint8_t byte;
    int i;

    for(i = 0; i < 32; i+=8)
    {
        byte = (bytes >> i) & 0xff;
        aux |= byte << (32 - 8 - i);
    }
    return aux;
}