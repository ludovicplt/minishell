/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** make my_printf
*/

#include <stdarg.h>
#include "includes/my_print.h"
#include "my.h"

static int my_local_printf_putstr(va_list *ap)
{
    char *tmp = (void *)0;

    tmp = va_arg(*ap, char *);
    return (my_putstr(tmp));
}

static int call_tab( va_list *ap, char str)
{
    int i = 0;
    const struct printfunc operate[10] = {
        {'d', &my_put_nbr_int},
        {'i', &my_put_nbr_int},
        {'s', &my_local_printf_putstr},
        {'c', &my_putchar_int},
        {'o', &convert_oct},
        {'x', &convert_hexa},
        {'X', &convert_hexa_maj},
        {'u', &convert_dec},
        {'p', &my_putpointer},
        {'S', &my_ess},
    };

    while (i != 10) {
        if (operate[i].a == str)
            return (operate[i].func(ap));
        i++;
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    int index = 0;
    va_list(ap);
    int count = 0;

    va_start(ap, format);
    while (format[index] != '\0') {
        if (format[index] == '%' && format[index + 1] == '%') {
            count = count + my_putchar('%');
            index += 2;
        } else if (format[index] == '%' && format[index + 1] != '%') {
            index++;
            count = count + call_tab(&ap, format[index]);
            index++;
        } else {
            count = count + my_putchar(format[index]);
            index++;
        }
    }
    va_end(ap);
    return (count);
}
