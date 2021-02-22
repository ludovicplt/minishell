/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** coredump
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "my_print.h"
#include "minishell.h"

void core_endler_three(int sig)
{
    int siginfo = WTERMSIG(sig);
    char *str = NULL;

    switch (siginfo) {
        case SIGABRT:
            str = "Abort";
            break;
        case SIGBUS:
            str = "Bus error";
            break;
        case SIGSEGV:
            str = "Segmentation fault";
            break;
        default:
            return;
    }
    if (WCOREDUMP(sig))
        my_perror(my_strcat(str, " (core dumped)\n"));
    else
        my_perror(my_strcat(str, "\n"));
}

void core_endler_two(int sig, shell_t *tab)
{
    int siginfo = WTERMSIG(sig);
    char *str = NULL;

    tab->ret = 0;
    switch (siginfo) {
        case SIGILL:
            str = "Illegal instruction";
            break;
        case SIGFPE:
            str = "Floating exception";
            break;
        default:
            core_endler_three(sig);
            return;
    }
    if (WCOREDUMP(sig))
        my_perror(my_strcat(str, " (core dumped)\n"));
    else
        my_perror(my_strcat(str, "\n"));
}

void core_endler(int sig, shell_t *tab)
{
    if (WIFSIGNALED(sig)) {
        core_endler_two(sig, tab);
    }
}

void my_wait(shell_t *tab, pid_t pid)
{
    do {
        waitpid(pid, &tab->ret, 0);
    } while (!WIFEXITED(tab->ret) && !WIFSIGNALED(tab->ret));
}
