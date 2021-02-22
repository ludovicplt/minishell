/*
** EPITECH PROJECT, 2021
** lib_my
** File description:
** my_str_is_alnum
*/

#include "my.h"

int is_alnum(char c)
{
    return (is_alpha(c) || is_num(c) || c == '_');
}

int my_str_isalnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_alnum(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
