/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_unsetenv.c
*/

#include "../../include/my.h"

void refresh_env_loop(my_env_t *m, char *str, int i, int j)
{
    for (; j != i; j += 1)
        m->env[j] = m->env[j + 1];
    return;
}

char **refresh_env(my_env_t *m, char *str)
{
    int i = 0, j = 0;
    for (; m->env[i] != 0; i += 1);
    for (; j != i; j += 1) {
        if (my_strcmp2(m->env[j], str) == 0) {
            refresh_env_loop(m, str, i, j);
            m->env[j] = 0;
            return (m->env);
        }
    }
    return (m->env);
}

int if_unsetenv(my_env_t *m)
{
    char *str = malloc(sizeof(char) * 4096);
    str = my_strdup(m->tab[1]);
    str = my_strcat(str, "=");
    int j = pos_env(m, str);
    if (my_strcmp2(m->env[j], str) == 0)
        m->env = refresh_env(m, str);
    return (0);
}

int my_unsetenv(my_env_t *m, int *ret)
{
    if (m->tab[1] == NULL) {
        *ret = 1, m->verif_and = 1;
        return (print_error(m->tab[0], ": Too few arguments.\n"));
    } else
        if_unsetenv(m);
    return (0);
}
