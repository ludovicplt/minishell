/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** directory usage
*/

#include "my.h"
#include "my_print.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void get_old(shell_t *tab)
{
    replace_env(&tab->env, my_strcat("OLDPWD=", get_env_char(*tab, "PWD=")),
            get_env_pos(*tab, "OLDPWD="));
}

void dir_two(shell_t *tab)
{
    char *str = malloc(sizeof(char) * 255);

    if (chdir(tab->av[1]) == 0) {
        str = getcwd(str, 255);
        get_old(tab);
        replace_env(&tab->env, my_strcat("PWD=", str),
                get_env_pos(*tab, "PWD="));
    } else {
        tab->ret = 1;
        if (errno == EACCES)
            my_perror(my_strcat(tab->av[1], ": Permission denied.\n"));
        else
            my_perror(my_strcat(tab->av[1], ": No such file or directory.\n"));
        tab->ret = 84;
    }
    free(str);
}

void directory(shell_t *tab)
{
    char *str = NULL;

    if (my_strcmp(tab->av[1], "~") == 0) {
        str = get_env_char(*tab, "HOME=");
        if (chdir(str) == 0) {
            get_old(tab);
            replace_env(&tab->env, my_strcat("PWD=", str),
                    get_env_pos(*tab, "PWD="));
        }
    } else if (my_strcmp(tab->av[1], "-") == 0) {
        str = get_env_char(*tab, "OLDPWD=");
        if (chdir(str) == 0) {
            replace_env(&tab->env, my_strcat("PWD=", str),
                    get_env_pos(*tab, "PWD="));
        } else {
            my_perror(": No such file or directory.\n");
            tab->ret = 84;
        }
    } else {
        dir_two(tab);
    }
}

char **emp_old(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strncmp(tab[i], "OLDPWD=", 7) == 0)
            replace_env(&tab, my_strdup("OLDPWD="), i);
        i++;
    }
    return (tab);
}

int set_one_env(shell_t *tab)
{
    char *var = my_strcat(tab->av[1], "=");

    if (tab->ac == 2) {
        if (get_env_pos(*tab, var) != -1) {
            replace_env(&tab->env, var, get_env_pos(*tab, var));
        } else {
            tab->env = put_in_tab(tab->env, var);
        }
        return (0);
    } else {
        return (-1);
    }
}
