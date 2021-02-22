/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** put my str in upcase
*/

char *my_strupcase(char *str)
{
    int e = 0;

    while ( str[e] != '\0') {
        if ('a' <= str[e] && str[e] <= 'z') {
            str[e] = str[e] - 32;
        }
        e++;
    }
    return (str);
}