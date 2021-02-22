/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** say if a string contain only alphabetical character
*/

#include <stdlib.h>
#include <stdio.h>

int is_num(char str);

int my_str_isnum(char const *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

int is_num(char str)
{
    return ('0' <= str && str <= '9');
}
