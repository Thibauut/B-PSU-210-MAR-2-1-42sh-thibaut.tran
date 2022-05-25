/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_check_cmd.c
*/

#include "../include/my.h"

int my_cmd(my_env_t *m, int *ret)
{
    M_CMP(m->tab[0], "cd") == 0 ? cd(m, ret) : 0;
    M_CMP(m->tab[0], "exit") == 0 ? my_exit(m) : 0;
    M_CMP(m->tab[0], "setenv") == 0 ? my_setenv(m, ret) : 0;
    M_CMP(m->tab[0], "unsetenv") == 0 ? my_unsetenv(m, ret) : 0;
    M_CMP(m->tab[0], "env") == 0 ? my_env(m, ret) : 0;
    my_strcmp2(m->tab[0], "./") == 0 ? exec(m, ret) : 0;
    return (0);
}

int check_cmd(char *line, my_env_t *m, int *ret)
{
    if (M_CMP(m->tab[0], "exit") == 0 || M_CMP(m->tab[0], "setenv") == 0
    || M_CMP(m->tab[0], "unsetenv") == 0 || M_CMP(m->tab[0], "cd") == 0
    || M_CMP(m->tab[0], "env") == 0 || my_strcmp2(m->tab[0], "./") == 0)
        my_cmd(m, ret);
    else {
        if (path_cmd(m, ret) == 0) {
            *ret = 1;
            return (print_error(m->tab[0], ": Command not found.\n"));
        }
    }
    return (0);
}

int check_cmd2(char *line, my_env_t *m, int *ret)
{
    if (M_CMP(m->tab[0], "exit") == 0 || M_CMP(m->tab[0], "setenv") == 0
    || M_CMP(m->tab[0], "unsetenv") == 0 || M_CMP(m->tab[0], "cd") == 0
    || M_CMP(m->tab[0], "env") == 0 || my_strcmp2(m->tab[0], "./") == 0)
        my_cmd(m, ret);
    else {
        if (path_cmd2(m, ret) == 0) {
            *ret = 1;
            return (print_error(m->tab[0], ": Command not found.\n"));
        }
    }
    return (0);
}
