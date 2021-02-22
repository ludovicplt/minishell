/*
** EPITECH PROJECT, 2020
** my_ess.c
** File description:
** big s
*/

#include <stdarg.h>
#include "includes/my_print.h"
#include <unistd.h>

static void convert_octal_ascii(int number)
{
    if (number <= 7) {
        write(1, "00", 2);
        convert(number, "01234567");
    } else if (number <= 64) {
        my_putchar('0');
        convert(number, "01234567");
    } else {
        convert(number, "01234567");
    }
}

int my_ess(va_list *ap)
{
    char *str = va_arg(*ap, char *);
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] <= 32 || str[i] >= 127) {
            my_putchar('\\');
            count++;
            convert_octal_ascii(str[i]);
            count += 3;
        } else {
            my_putchar(str[i]);
            count++;
        }
        i++;
    }
    return (count);
}
