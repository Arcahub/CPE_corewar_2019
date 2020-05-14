/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** str_to_word_array
*/

#include <stdlib.h>

char *my_strndup(char *, int);

static void fill_array(char **array, char *str)
{
    int size = 0;
    int index = 0;

    while (*str != '\0') {
        for (; (*str == ' ' || *str == '\t') && *str != '\0'; str = str +1);
        for (size = 0; *(str + size) != ' ' && *(str + size) != '\t' &&
        *(str + size) != '\0'; size++);
        if (size != 0) {
            array[index] = my_strndup(str, size);
            index++;
        }
        str = str + size;
    }
}

char **str_to_word_array(char *str)
{
    int count_word = 0;
    char **array = NULL;

    if (str[0] != ' ' && str[0] != '\t')
        count_word++;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] > 32 &&  str[i] < 123 && (str[i - 1] == ' ' ||
        str[i - 1] == '\t'))
            count_word++;
    }
    array = malloc(sizeof(char *) * (count_word + 1));
    array[count_word] = NULL;
    fill_array(array, str);
    return (array);
}