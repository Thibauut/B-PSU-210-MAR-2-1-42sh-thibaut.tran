/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_setenv2.c
*/

#include "../../include/my.h"

int my_env_exist(my_env_t *m)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(m->str)));
    for (int j = 0; m->str[j] != '='; j += 1)
        tmp[j] = m->str[j];
    tmp = my_strcat(tmp, "=");
    for (int i = 0; m->env[i] != 0; i += 1) {
        if (my_strcmp2(m->env[i], tmp) == 0)
            m->env[i] = my_strdup(m->str);
    }
    return (0);
}

int my_new_env(my_env_t *m)
{
    int i = 0;
    for (; m->env[i] != 0; i += 1);
    m->env[i] = my_strdup(m->str);
    m->env[i + 1] = 0;
    return (0);
}
