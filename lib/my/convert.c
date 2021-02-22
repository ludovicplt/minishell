/*
** EPITECH PROJECT, 2020
** my_put_octal.c
** File description:
** put octal
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "includes/my_print.h"

int convert(unsigned int number, char *base)
{
    unsigned int nb = my_strlen(base);
    int count = 0;

    if (number >= nb ) {
        count = count + convert((number / nb), base);
    }
    my_putchar(base[number % nb]);
    count++;
    return (count);
}