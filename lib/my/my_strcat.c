/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** cat to string
*/

#include "./includes/my.h"
#include "./includes/my_print.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strcat(char *str, char *src)
{
    size_t size = my_strlen(str) + my_strlen(src);
    char *new = malloc(sizeof(char) * (size + 1));

    if (str) {
        my_strcpy(new, str);
        my_strcpy(new + my_strlen(new), src);
    } else
        new = my_strcpy(new, src);
    return (new);
}
