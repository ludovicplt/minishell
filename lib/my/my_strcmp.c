/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** lol
*/

int my_strcmp(char const *s1, char const *s2)
{
    int e = 0;

    while ( s1[e] != '\0' && s2[e] != '\0' && s1[e] == s2[e] ) {
        e++;
    }
    return (s1[e] - s2[e]);
}
