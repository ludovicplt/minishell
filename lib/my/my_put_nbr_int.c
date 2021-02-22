/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print all
*/

#include <stdarg.h>

int my_put_nbr(int nb);

int my_putchar(char c);

int my_put_nbr_int(va_list *ap)
{
    int nb = va_arg(*ap, int);
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        count++;
    }
    if ( nb >= 10) {
        count = count + my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
        count++;
    } else {
        my_putchar(nb + '0');
        count++;
    }
    return (count);
}