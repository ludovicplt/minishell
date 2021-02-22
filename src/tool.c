/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** tools
*/

#include "my.h"
#include "my_print.h"
#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void my_perror(char *str)
{
    write (2, str, my_strlen(str));
}

char **env_cpy(char **env)
{
    int i = 0;
    int size = count_tab(env);
    char **env_cpy = malloc(sizeof(char *) * (size + 1));

    for (; i != size; i++) {
        if (env[i] != NULL)
            env_cpy[i] = my_strdup(env[i]);
    }
    env_cpy[i] = NULL;
    env_cpy = emp_old(env_cpy);
    return (env_cpy);
}

int unset_env(shell_t *tab)
{
    int index = get_env_pos(*tab, my_strcat(tab->av[1], "="));

    if (index != -1)
        tab->env = rm_tab(tab->env, index);
    return (0);
}

char *search_bin(shell_t *tab, char **path)
{
    char *ver = NULL;
    bool exe = false;
    int i = 0;
    int size = count_tab(path);

    while (exe != true && path != NULL && path[i] != NULL) {
        ver = my_strcat(path[i], "/");
        ver = my_strcat(ver, tab->av[0]);
        if (access(ver, 0) == 0) {
            exe = true;
            return (ver);
        }
        free(ver);
        ver = NULL;
        if (size == i)
            return (NULL);
        i++;
    }
    return (NULL);
}

int set_env(shell_t *tab)
{
    char *var = NULL;

    if (tab->ac > 3) {
        my_perror("setenv: Too many arguments.\n");
        tab->ret = 84;
        return (0);
    }
    if (check_env_var(tab) == 1) {
        return (0);
    }
    if (set_one_env(tab) == 0)
        return (0);
    var = my_strcat(tab->av[1], "=");
    if (get_env_pos(*tab, var) != -1) {
        replace_env(&tab->env, my_strcat(var, tab->av[2]),
                get_env_pos(*tab, var));
    } else {
        tab->env = put_in_tab(tab->env, my_strcat(var, tab->av[2]));
    }
    free(var);
    return (0);
}
