/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** exec function
*/

#include "my.h"
#include "my_print.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int quit(shell_t *tab)
{
    tab->ac = count_tab(tab->av);
    if (tab->ac == 1)
        exit(0);
    else
        exit(my_getnbr(tab->av[1]));
}

int display_env(shell_t *tab)
{
    for ( int i = 0; tab->env[i] != NULL; i++)
        my_puts(tab->env[i]);
    return (0);
}

int process(shell_t *tab)
{
    struct built_in build[7] = {{"env", &display_env},
        {"exit", &my_exit},
        {"pwd", &pwd},
        {"cd", &cd},
        {"setenv", &set_env},
        {"unsetenv", &unset_env},
        {NULL, NULL} };
    int i  = 0;

    tab->ac = count_tab(tab->av);
    while (build[i].comp != NULL) {
        if (my_strcmp(build[i].comp, tab->av[0]) == 0) {
            build[i].func(tab);
            return (1);
        }
        i++;
    }
    return (0);
}

char **get_path(char *str)
{
    char **new_tab = malloc(sizeof(char *) * 1);
    char *new_str = str + 5;
    char *str_new = NULL;

    new_tab[0] = NULL;
    while ((str_new = strtok_r(new_str, ":", &new_str))) {
        new_tab = put_in_tab(new_tab, str_new);
    }
    return (new_tab);
}

char *guess_bin(shell_t *tab)
{
    char **path = NULL;
    int i = 0;

    if (access(tab->av[0], 0) == 0)
        return (tab->av[0]);
    while (tab->env[i] != NULL) {
        if (my_strncmp(tab->env[i], "PATH=", 5) == 0)
            break;
        i++;
    }
    if (tab->env[i] != NULL)
        path = get_path(my_strdup(tab->env[i]));
    i = 0;
    return (search_bin(tab, path));
}
