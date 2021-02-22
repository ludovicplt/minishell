/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** return power with recursive
*/

int my_compute_power_rec(int nb, int p)
{
    int res = nb;
    int verif = p;

    if (verif < 0) {
        return (0);
    }else if (verif == 0) {
        return (1);
    }
    if (p != 1)
        nb = res * my_compute_power_rec(nb, (p - 1));
    return (nb);
}