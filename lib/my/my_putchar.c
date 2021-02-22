/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** putchar
*/

#include <unistd.h>

#include <stdarg.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
