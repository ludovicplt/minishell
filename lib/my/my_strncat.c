/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** bonjour
*/

int my_strlen(char *str);

char *my_strncat(char *dest, char const *src, int n)
{
    int k = my_strlen(dest);
    int i = 0;

    while ( i != n) {
        dest[k+i] = src[i];
        i++;
    }
    dest[k+i] = '\0';
    return (dest);
}
