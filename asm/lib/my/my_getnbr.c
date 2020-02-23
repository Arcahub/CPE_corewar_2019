/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** display int enter without other character
*/

#include "my.h"

static int sign_nbr(int nbr, int sign)
{
    int divide_int = sign % 2;

    if (divide_int == 0) {
        return (nbr);
    }
    nbr = - nbr;
    return (nbr);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 0;
    int nbr = 0;
    int v = 0;

    while (str[i] != '\0' && v == 0) {
        if (str[i] == '-') {
            sign++;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - 48;
        }
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+') {
            v = 1;
        }
        i++;
    }
    return (sign_nbr(nbr, sign));
}