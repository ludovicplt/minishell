/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** verify if a number is a prime
*/

int my_is_prime(int nb)
{
    int i = 1;
    int verif = 0;

    while (i <= nb) {
        if ( (nb % i) == 0 ) {
            verif++;
        }
        i++;
    }
    if (verif == 2) {
        return (1);
    } else if ( verif > 2 || verif < 2) {
        return (0);
    }
    return (0);
}
