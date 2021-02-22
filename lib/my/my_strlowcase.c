/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** put in low case strings
*/

char *my_strlowcase(char *str)
{
    int e = 0;

    while ( str[e] != '\0') {
        if ( 'A' <= str[e] && str[e] <= 'Z') {
            str[e] = str[e] + 32;
        }
        e++;
    }
    return (str);
}