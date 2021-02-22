/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print all
*/

#include <stdarg.h>
#include <stdlib.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        count++;
    }
    if ( nb >= 10) {
        my_put_nbr(nb / 10);
        count = count + my_putchar(nb % 10 + '0');
    } else {
        my_putchar(nb + '0');
        count++;
    }
    return (count);
}
