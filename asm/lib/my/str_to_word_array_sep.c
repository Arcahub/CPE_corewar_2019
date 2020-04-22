/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** str_to_word_array
*/

#include <stdlib.h>

char *my_strndup(char *, int);

static void fill_array(char **array, char *str, char sep)
{
    int size = 0;
    int index = 0;

    while (*str != '\0') {
        for (; (*str == sep) && *str != '\0'; str = str +1);
        for (size = 0; *(str + size) != sep && \
        *(str + size) != '\0'; size++);
        if (size != 0) {
            array[index] = my_strndup(str, size);
            index++;
        }
        str = str + size;
    }
}

char **str_to_word_array_sep(char *str, char sep)
{
    int count_word = 0;
    char **array = NULL;

    if (str[0] != sep)
        count_word++;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] > 32 &&  str[i] < 123 && (str[i - 1] == sep))
            count_word++;
    }
    array = malloc(sizeof(char *) * (count_word + 1));
    for (int i = 0; i < count_word; array[i] = NULL, i++);
    array[count_word] = NULL;
    fill_array(array, str, sep);
    return (array);
}