/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** find prime sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int prime = 0;

    while ( prime <= 1) {
        if ( my_is_prime(nb) == 1) {
            prime = 1;
            return (nb);
        }
        nb++;
    }
    return (0);
}