/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** lol
*/

int my_strlen(char *str);

int my_strncmp(char *s1, char *s2, int n)
{
    int e = 0;
    int rst = 0;
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 < n || len_s2 < n)
        return (-1);
    while (s1[e] != '\0' && s2[e] != '\0' && e != n) {
        rst += (s1[e] - s2[e]);
        e++;
    }
    return (rst);
}
