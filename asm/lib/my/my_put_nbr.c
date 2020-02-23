/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** print all digits
*/

#include "my.h"

static void display_nbr(int n, int digits)
{
    int digit = 0;
    int ten = 1;
    int print = 0;

    while (digits >= 0) {
        for (int d = digits; d > 0; d--) {
            ten = ten * 10;
        }
        digit = (n / ten);
        n = n - (digit * ten);
        print = digit + 48;
        my_putchar(print);
        ten = 1;
        digits--;
    }
}

static int get_int_length(int n)
{
    int length = 0;
    int digits = 0;

    while (n >= 10) {
        digits++;
        n = n / 10;
    }
    return digits;
}

int my_put_nbr(int n)
{
    int digits = 0;

    if (n < 0) {
        my_putchar('-');
        n = - n;
    }
    digits = get_int_length(n);
    display_nbr(n, digits);
    return 0;
}