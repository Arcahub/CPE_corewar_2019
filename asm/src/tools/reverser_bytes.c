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
    uint8_t byte = 0;
    int i = 0;

    for (i = 0; i < 32; i += 8) {
        byte = (bytes >> i) & 0xff;
        aux |= byte << (32 - 8 - i);
    }
    return (aux);
}

uint32_t reverse_bytes32(uint32_t bytes)
{
    uint32_t aux = 0;
    uint8_t byte = 0;
    int i = 0;

    for (i = 0; i < 32; i += 8) {
        byte = (bytes >> i) & 0xff;
        aux |= byte << (32 - 8 - i);
    }
    return (aux);
}

uint32_t reverse_bytes16(uint32_t bytes)
{
    uint32_t aux = 0;
    uint8_t byte = 0;
    int i = 0;

    for (i = 0; i < 16; i += 8) {
        byte = (bytes >> i) & 0xff;
        aux |= byte << (16 - 8 - i);
    }
    return (aux);
}