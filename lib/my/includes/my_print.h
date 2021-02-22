/*
** EPITECH PROJECT, 2020
** my_print.h
** File description:
** header my_print
*/

#ifndef _MY_PRINT_H_
#define _MY_PRINT_H_

#include <stdarg.h>
#include "my.h"

int my_printf(const char *format, ...);
int my_putchar_int(va_list *ap);
int my_put_nbr_int(va_list *ap);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_compute_power_rec(int nb, int p);
char *my_revstr(char *str);
int my_put_octal(va_list *ap);
int my_strlen(char const *str);
int convert( unsigned int nunber, char *base);
char *my_strdup(char const *str);
int convert_hexa(va_list *ap);
int convert_dec(va_list *ap);
int convert_oct(va_list *ap);
int convert_hexa_maj(va_list *ap);
int my_putpointer(va_list *ap);
int my_ess(va_list *ap);
struct printfunc
{
    char a;
    int (*func)(va_list *ap);
};



#endif /* _MY_PRINT_H_ */
