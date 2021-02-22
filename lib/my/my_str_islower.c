/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** say if a string contain only alphabetical character
*/

int is_lower(char str);

int my_str_islower(char const *str)
{
    int e = 0;
    int str_lower = 1;

    while (str[e] != '\0' && str_lower == 1) {
        if (is_lower(str[e]) == 0) {
            str_lower = 0;
        }
        e++;
    }
    if ( str_lower == 1 || e == 0) {
        return (1);
    } else if ( str_lower == 0 ) {
        return (0);
    }
    return (0);
}

int is_lower(char str)
{
    if ('a' <= str && str <= 'z') {
        return (1);
    } else {
        return (0);
    }
    return (0);
}