/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** say if a string contain only alphabetical character
*/

int is_print(char str);

int my_str_isprintable(char const *str)
{
    int e = 0;
    int str_print = 1;

    while (str[e] != '\0' && str_print == 1) {
        if (is_print(str[e]) == 0) {

            str_print = 0;
        }
        e++;
    }
    if ( str_print == 1 || e == 0) {
        return (1);
    } else if ( str_print == 0 ) {
        return (0);
    }
    return (0);
}

int is_print(char str)
{
    if ( 32 <= str && str <= 126) {
        return (1);
    } else {
        return (0);
    }
    return (0);
}