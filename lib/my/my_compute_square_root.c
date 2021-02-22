/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** square
*/

int my_compute_square_root(int nb)
{
    int a = 1;
    int i = 0;

    while ( i <= nb ) {
        i = a * a;
        if ( i == nb ) {
            return (a);
        } else if (i > nb || nb <= 0) {
            return (0);
        }
        a++;
    }
    return (0);
}