/*
** EPITECH PROJECT, 2020
** my_convertbase.c
** File description:
** convert base
*/

#include <stdarg.h>

#include "includes/my_print.h"

int convert_hexa(va_list *ap)
{
    unsigned int nb = va_arg(*ap, unsigned int);
    int count = 0;

    count = count + convert(nb, "0123456789abcdef");
    return (count);
}

int convert_hexa_maj(va_list *ap)
{
    int nb = va_arg(*ap, unsigned int);
    int count = 0;

    count = count + convert(nb, "0123456789ABCDEF");
    return (count);
}

int convert_dec(va_list *ap)
{
    int nb = va_arg(*ap, unsigned int);
    int count = 0;

    count = count + convert(nb, "0123456789");
    return (count);
}

int convert_oct(va_list *ap)
{
    int nb = va_arg(*ap, unsigned int);
    int count = 0;

    count = count + convert(nb, "01234567");
    return (count);
}