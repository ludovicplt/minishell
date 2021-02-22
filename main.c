/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** make tcsh
*/

#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_print.h"
#include "minishell.h"

char *remove_n(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    while (str[i] != '\n') {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char **add_in_tab(char *arg)
{
    char **args = malloc(sizeof(char *) * 1);
    char *str = remove_n(arg);
    char *new_str = NULL;

    args[0] = NULL;
    while ((new_str = strtok_r(str, " \t\n", &str))) {
        args = put_in_tab(args, new_str);
        new_str = NULL;
    }
    return (args);
}

void exe(shell_t *tab)
{
    pid_t pid = 0;

    tab->fullpath = guess_bin(tab);
    if (tab->fullpath != NULL) {
        pid = fork();
        if (pid == 0)
            execve(tab->fullpath, tab->av, tab->env);
        else
            my_wait(tab, pid);
        if (pid == 0)
            exit (0);
    } else {
        tab->ret = 84;
        my_perror(my_strcat(tab->av[0], ": Command not found.\n"));
        return;
    }
    if (WIFSIGNALED(tab->ret))
        core_endler(tab->ret, tab);
    tab->ret = WEXITSTATUS(tab->ret);
}

void free_doubly_array(char ***tab)
{
    int i = 0;

    while ((*tab)[i] != NULL) {
        free((*tab)[i]);
        i++;
    }
    free(*tab);
    *tab = NULL;
}

int main(int argc, char **argv, char **env)
{
    char *str = NULL;
    size_t len = 0;
    shell_t tab = {0};

    (void)argv;
    (void)argc;
    tab.env = env_cpy(env);
    (isatty(STDIN_FILENO)) ? write(1, "$> ", 3) : 0;
    while (getline(&str, &len, stdin) > 0) {
        if (str[0] != '\n') {
            tab.av = add_in_tab(str);
            if (process(&tab) == 0) {
                exe(&tab);
                free_doubly_array(&tab.av);
            }
        }
        (isatty(STDIN_FILENO)) ? write(1, "$> ", 3) : 0;
    }
    free_doubly_array(&tab.env);
    return (tab.ret);
}
