/*
** EPITECH PROJECT, 2020
** capitalised
** File description:
** put first letter of a word in capital letter
*/

int is_special(char str);

int is_up(char str);

char *my_strcapitalize(char *str)
{
    int e = 0;

    while (str[e] != '\0') {
        if ( 'a' <= str[e] && str[e] <= 'z' && is_special(str[e-1]) == 1) {
            str[e] = str[e] - 32;
        } else if ((is_up(str[e]) == 1) && (is_up(str[e-1]) == 1)) {
            str[e] = str[e] + 32;
        }
        e++;
    }
    return (str);
}

int is_special(char str)
{
    if ( str == '-' || str == ' ' || str == '+' || str == 0) {
        return (1);
    } else {
        return (0);
    }
    return (0);
}

int is_up(char str)
{
    if (('A' <= str) && (str <= 'Z')) {
        return (1);
    } else {
        return (0);
    }
}