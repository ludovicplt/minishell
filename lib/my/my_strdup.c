/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <unistd.h>
#include "./includes/my.h"
#include "./includes/my_print.h"

char *my_strdup(char const *str)
{
    char *strcp = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (str == NULL)
        write(1, "lol", 3);
    if (strcp != NULL)
        my_strcpy(strcp, str);
    return (strcp);
}
