/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** say if a string contain only alphabetical character
*/

int is_alpha(char str);

int my_str_isalpha(char const *str)
{
    int e = 0;
    int str_alpha = 1;

    while (str[e] != '\0' && str_alpha == 1) {
        if (is_alpha(str[e]) == 0) {
            str_alpha = 0;
        }
        e++;
    }
    if ( str_alpha == 1 || e == 0) {
        return (1);
    } else if ( str_alpha == 0 ) {
        return (0);
    }
    return (0);
}

int is_alpha(char str)
{
    if (('a' <= str && str <= 'z') || ('A' <= str && str <= 'Z')) {
        return (1);
    } else {
        return (0);
    }
}
