/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** minishell.h
*/

#ifndef _MINISHELL_H_
#define _MINISHELL_H_

#include <sys/types.h>

typedef struct shell {
    int ac;
    char **av;
    char **env;
    char *fullpath;
    int ret;
} shell_t;

void my_wait(shell_t *tab, pid_t pid);
int is_alpha(char c);
int check_env_var(shell_t *tab);
void free_doubly_array(char ***tab);
char *guess_bin(shell_t *tab);
int count_tab(char **tab);
char **put_in_tab(char **tab, char *str);
int process(shell_t *tab);
int pwd(shell_t *tab);
int cd(shell_t *tab);
int get_env_pos(shell_t tab, char *);
char *get_env_char(shell_t tab, char *ch);
void my_perror(char *str);
void directory(shell_t *tab);
void replace_env(char ***env, char *rep, int index);
void get_old(shell_t *tab);
char **rm_tab(char **tab, int index);
int set_env(shell_t *tab);
int unset_env(shell_t *tab);
char **env_cpy(char **env);
void core_endler(int sig, shell_t *tab);
void core_endler_two(int sig, shell_t *tab);
char *search_bin(shell_t *tab, char **path);
int my_exit(shell_t *tab);
int is_num(char c);
int display_env(shell_t *tab);
char **emp_old(char **tab);
int set_one_env(shell_t *tab);

struct built_in {
    char *comp;
    int (*func)(shell_t *tab);
};

#endif /* _MINISHELL_H_ */


