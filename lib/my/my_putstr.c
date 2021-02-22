/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** print string
*/

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

void my_putchar(char c);

ssize_t my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str)));
}

ssize_t my_put_multiple_str(size_t n, ...)
{
    size_t count = 0;
    char *tmp = NULL;
    va_list ap;

    va_start(ap, n);
    for (size_t i = 0; i < n; i++) {
        tmp = va_arg(ap, char *);
        count += my_putstr(tmp);
    }
    return (count);
}

ssize_t my_puts(char const *str)
{
    return (my_putstr(str) + write(1, "\n", 1));
}
