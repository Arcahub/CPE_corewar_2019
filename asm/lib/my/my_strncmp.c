/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** compare n chara of string
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] - s2[i] != 0) {
            return (s1[i] - s2[i]);
        }
    }
    if (i != n)
        return (1);
    return (0);
}