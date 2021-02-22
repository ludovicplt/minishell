/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int d;
    d = *a;
    *a = *b;
    *b = d;
}