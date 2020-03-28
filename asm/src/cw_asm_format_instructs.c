/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_compile_instructs
*/

#include "my.h"
#include "cw_asm.h"
#include <unistd.h>
#include <stdlib.h>

int cw_asm_get_parameters(instruct_t *instruct, char *line, int *i)
{
    char **params = NULL;
    int j = 0;

    if (*line == '\0')
        return (84);
    params = str_to_word_array_sep(line, SEPARATOR_CHAR);
    if (params == NULL)
        return (84);
    for (int h = 0; h < MAX_ARGS_NUMBER; instruct->parameters[h] = NULL, h++);
    instruct->coding_byte = 0;
    for (; params[j] && j < MAX_ARGS_NUMBER; j++)
        instruct->parameters[j] = my_strdup(params[j]);
    for (j = 0; params[j]; j++)
        free(params[j]);
    free(params);
    if (j > MAX_ARGS_NUMBER)
        return (84);
    return (cw_asm_check_params(instruct));
}

unsigned int cw_asm_get_instruct_code(char *line, int *i)
{
    if (*line == '\0')
        return (0);
    for (int j = 0; op_tab[j].mnemonique; j++) {
        if (my_strncmp(line, op_tab[j].mnemonique, \
        my_strlen(op_tab[j].mnemonique)) == 0) {
            *i += my_strlen(op_tab[j].mnemonique);
            return (op_tab[j].code);
        }
    }
    return (0);
}

char *cw_asm_instruct_get_label(char *line, int *i)
{
    int j = 0;

    if (*line == '\0')
        return (NULL);
    for (; line[j] != '\0' && line[j] != LABEL_CHAR; j++, (*i)++) {
        if (my_findchr(LABEL_CHARS, line[j]))
            break;
    }
    if (line[j] == LABEL_CHAR)
        return (my_strndup(line, j));
    return (NULL);
}

instruct_t *cw_asm_format_instruct(char *line, instruct_t *last)
{
    instruct_t *instruct = malloc(sizeof(instruct_t));
    int i = 0;

    if (instruct == NULL)
        return (NULL);
    instruct->next = last;
    for (int h = 0; h < MAX_ARGS_NUMBER; instruct->parameters[h] = NULL, h++);
    instruct->label = cw_asm_instruct_get_label(line, &i);
    for (; line[i] == ' '; i++);
    instruct->instruct_code = cw_asm_get_instruct_code(line + i, &i);
    if (instruct->instruct_code == 0)
        return (instruct);
    for (; line[i] == ' '; i++);
    if (cw_asm_get_parameters(instruct, line + i, &i) == 84) {
        free(instruct);
        return (NULL);
    }
    return (instruct);
}

int cw_asm_format_instructs(instruct_t **instructs_list, FILE *fdin)
{
    char *line = my_get_line(fdin);
    instruct_t *tmp = NULL;

    for (; line; line = my_get_line(fdin)) {
        printf("%s\n", line);
        if (line[0] == '\0')
            continue;
        tmp = cw_asm_format_instruct(line, *instructs_list);
        free(line);
        if (tmp == NULL)
            return (84);
        *instructs_list = tmp;
    }
    return (0);
}