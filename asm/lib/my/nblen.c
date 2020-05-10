/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** return the number len.
*/

int my_nblen(int nb)
{
    int length = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        length++;
        nb /= 10;
    }
    return length;
}