/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tools
*/

#ifndef CW_ASM_TOOLS_H_
#define CW_ASM_TOOLS_H_

#include <stdint.h>

uint32_t reverse_bytes(uint32_t bytes);
uint32_t reverse_bytes32(uint32_t bytes);
uint32_t reverse_bytes16(uint32_t bytes);

int my_getnbr(char const *str);
char *my_trimline(char *line);
char **str_to_word_array_sep(char *str, char sep);

#endif /* !CW_ASM_TOOLS_H_ */
