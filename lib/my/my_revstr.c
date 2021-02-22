/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string
*/

#include "includes/my_print.h"

void put_str(char *str);

char *my_revstr(char *str)
{
    int i = 0;
    int e = 0;
    int f = 0;
    char letter;

    while (str[i] != '\0') {
        i = i + 1;
    }
    i--;
    e = (i / 2);
    while (  i  >= e ) {
        letter = str[f];
        str[f] = str[i];
        str[i] = letter;
        f++;
        i = i - 1;
    }
    return (str);
}