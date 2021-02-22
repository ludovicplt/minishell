/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** adding some builtin
*/

#include "minishell.h"
#include "my.h"
#include "my_print.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void replace_env(char ***env, char *rep, int index)
{
    free((*env)[index]);
    (*env)[index] = rep;
}

int pwd(shell_t *tab)
{
    char *str = getcwd(NULL, 0);

    (void)tab;
    (str) ? my_puts(str) : 0;
    free(str);
    return (0);
}

char *get_env_char(shell_t tab, char *ch)
{
    int index = get_env_pos(tab, ch);

    if (index == -1)
        return ("");
    else {
        return (tab.env[index] + my_strlen(ch));
    }
}

int get_env_pos(shell_t tab, char *ch)
{
    int i = 0;

    while (my_strncmp(tab.env[i], ch, my_strlen(ch)) != 0) {
        if (tab.env[i] == NULL)
            return (-1);
        i++;
    }
    return (i);
}

void change_env(shell_t *tab, char *new_pwd)
{
    int env_pos = -1;

    env_pos = get_env_pos(*tab, "PWD=");
    if (env_pos != -1)
        replace_env(&tab->env, my_strcat("PWD=", new_pwd), env_pos);
    else
        tab->env = put_in_tab(tab->env, my_strcat("PWD=", new_pwd));
}

int cd(shell_t *tab)
{
    char *new_pwd = NULL;

    tab->ac = count_tab(tab->av);
    if (tab->ac == 1) {
        new_pwd = get_env_char(*tab, "HOME=");
        if (chdir(new_pwd) == 0) {
            get_old(tab);
            change_env(tab, new_pwd);
        }
        return (0);
    }
    directory(tab);
    return (0);
}
