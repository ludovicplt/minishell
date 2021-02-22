/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** putchar
*/

#include <unistd.h>

#include <stdarg.h>

int my_putchar_int(va_list *ap)
{
    char c = va_arg(*ap, int);

    write(1, &c, 1);
    return (1);
}