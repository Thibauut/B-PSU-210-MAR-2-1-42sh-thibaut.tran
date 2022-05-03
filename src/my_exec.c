/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_exec.c
*/

#include "../include/my.h"

void status_checker(int *ret, int status)
{
    if (status == SIGSEGV) {
        my_putstr_error("Segmentation fault.\n");
        *ret = 139;
    }
    if (status == SIGFPE) {
        my_putstr_error("Floating exception.\n");
        *ret = 136;
    }
    if (status == 139) {
        my_putstr_error("Segmentation fault (core dumped).\n");
        *ret = 139;
    }
    if (status == 136) {
        my_putstr_error("Floating exception (core dumped).\n");
        *ret = 136;
    }
}

void my_execve(char *path, char **env, int *ret, my_env_t *m)
{
    if (execve(path, m->tab, env) == -1);
        exit(EXIT_FAILURE);
}

void my_exec(char *path, char **env, int *ret, my_env_t *m)
{
    int status = 0;
    pid_t pid = fork();
    if (pid == -1)
        perror("fork ");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
        status != 0 && status != 256 ? *ret = 2 : 0;
        status_checker(ret, status);
    } else
        my_execve(path, env, ret, m);
}

void my_exec2(char *path, char **env, int *ret, my_env_t *m)
{
    int status = 0;
    pid_t pid = fork();
    if (pid == -1)
        perror("fork ");
    else if (pid > 0) {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
        status != 0 && status != 256 ? *ret = 2 : 0;
        status_checker(ret, status);
    } else
        my_execve(path, env, ret, m);
    fix_dup(m);
}

int exec(my_env_t *m, int *ret)
{
    int j = 0;
    char *stock = my_strdup(m->tab[0]);
    for (int i = 2; m->tab[0][i] != '\0'; i += 1) {
        m->tab[0][j] = m->tab[0][i];
        j += 1;
    }
    m->tab[0][j] = '\0';
    if (access(m->tab[0], X_OK) == 0)
        my_exec(stock, m->env, ret, m);
    else {
        *ret = 1;
        print_error(stock, ": No such file or directory\n");
    }
    return (0);
}
