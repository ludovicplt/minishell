/*
** EPITECH PROJECT, 2020
** my_putpointer.c
** File description:
** put pointer
*/

#include <stdarg.h>

#include <stdarg.h>

#include "includes/my_print.h"

int convert_p(long number, char *base)
{
    long nb = my_strlen(base);
    int count = 0;
    int e = 0;

    if (number >= nb ) {
        e = convert_p((number / nb), base);
        count = count + e;
    }
    my_putchar(base[number % nb]);
    count++;
    return (count);
}

int convert_hexa_p(long nb)
{
    return (convert_p(nb, "0123456789abcdef"));
}

int my_putpointer(va_list *ap)
{
    int i = 2;
    long nb = va_arg(*ap, long);
    int e = 0;

    my_putstr("0x");
    e = convert_hexa_p(nb);
    i = i + e;
    return (i);
}
