/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** say if a string contain only alphabetical character
*/

int is_upper(char str);

int my_str_isupper(char const *str)
{
    int e = 0;
    int str_upper = 1;

    while (str[e] != '\0' && str_upper == 1) {
        if (is_upper(str[e]) == 0) {

            str_upper = 0;
        }
        e++;
    }
    if ( str_upper == 1 || e == 0) {
        return (1);
    } else if ( str_upper == 0 ) {
        return (0);
    }
    return (0);
}

int is_upper(char str)
{
    if ('A' <= str && str <= 'Z') {
        return (1);
    } else {
        return (0);
    }
}