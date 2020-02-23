/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** copy n character to string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    dest[i] = '\0';
    return (dest);
}