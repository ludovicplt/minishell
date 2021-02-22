/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get number in a string
*/

int my_put_nbr(int c);

int my_getnbr(char const *str)
{
    int nb = 0;
    int is_neg = 0;
    int index = 0;

    while ((str[index] == '-'
    || str[index] == '+') && str[index] != '\0' ) {
        if (str[index] == '-') {
            is_neg++;
        }
        index++;
    }
    while (str[index] >= '0' && str[index] <= '9') {
        nb = ((nb * 10) + (str[index] - 48));
        if (str[index] < '0' || str[index] > '9')
            return (nb);
        index++;
    }
    if ((is_neg % 2) == 1)
        nb = nb * -1;
    return (nb);
}