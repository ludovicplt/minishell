/*
** EPITECH PROJECT, 2021
** Minishell1
** File description:
** fonction
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_print.h"
#include "minishell.h"

int count_tab(char **tab)
{
    int i = 0;
    if (tab != NULL) {
        while (tab[i] != NULL) {
            i++;
        }
    }
    return (i);
}

char **put_in_tab(char **tab, char *str)
{
    char **new_tab = NULL;
    int i = 0;
    int count = count_tab(tab);

    new_tab = malloc(sizeof(char *) * (count + 2));
    if (count != 0) {
        while (tab[i] != NULL) {
            if (tab[i] != NULL)
                new_tab[i] = my_strdup(tab[i]);
            i++;
        }
    }
    new_tab[i] = my_strdup(str);
    new_tab[i + 1] = NULL;
    return (new_tab);
}

int check_env_var(shell_t *tab)
{
    if (tab->ac == 1) {
        display_env(tab);
        return (1);
    }
    if (is_alnum(tab->av[1][0]) == 0 || is_num(tab->av[1][0]) == 1) {
        my_perror("setenv: Variable name must begin with a letter.\n");
        tab->ret = 84;
        return (1);
    } else if (my_str_isalnum(tab->av[1]) == 0) {
        my_perror("setenv: Variable name must"
                " contain alphanumeric characters.\n");
        tab->ret = 84;
        return (1);
    }
    return (0);
}

int my_exit(shell_t *tab)
{
    if (tab->ac > 2) {
        my_perror("exit: Expression Syntax.\n");
        tab->ret = 84;
        return (84);
    } else if ( tab->ac == 2 && is_num(tab->av[1][0]) == 1  &&
            my_str_isnum(tab->av[1]) == 1) {
        my_perror("exit: Badly formed number.\n");
        tab->ret = 84;
        return (84);
    }
    if (tab->ac == 2 && is_num(tab->av[1][0]) == 0) {
        my_perror("exit: Expression Syntax.\n");
        tab->ret = 84;
        return (84);
    }
    (tab->ac == 1) ? exit(tab->ret) : exit(my_getnbr(tab->av[1]));
    return (0);
}

char **rm_tab(char **tab, int index)
{
    int size = count_tab(tab);
    char **new_tab = malloc(sizeof(char *) * size);
    int inc = 0;
    int rm = 0;

    while (inc != (size - 1)) {
        if (inc == index)
            rm++;
        new_tab[inc] = my_strdup(tab[rm]);
        rm++;
        inc++;
    }
    new_tab[size - 1] = NULL;
    return (new_tab);
}
