/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tools
*/

#ifndef CW_ASM_TOOLS_H_
#define CW_ASM_TOOLS_H_

#include <stdint.h>

int my_getnbr(char const *str);
char *my_trimline(char *line);
char **str_to_word_array_sep(char *str, char sep);
char *my_itoa(int nb);
int my_nblen(int nb);

#endif /* !CW_ASM_TOOLS_H_ */
