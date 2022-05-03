/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_get_path.c
*/

#include "../include/my.h"

char *my_get_line(char **env, char *arg)
{
    char *line;
    int i = 0;
    for (; env[i] != 0; i += 1) {
        if (my_strcmp2(env[i], arg) == 0) {
            line = my_strdup(env[i]);
            line = clean_get(line);
        }
    }
    return (line);
}

int path_cmd(my_env_t *m, int *ret)
{
    m->path_cmd = malloc(sizeof(char *) * (tab_len(m->path) + 20));
    for (int i = 0; m->path[i] != 0; i += 1) {
        m->path_cmd[i] = malloc(sizeof(char) * (m_len(m->path[i]) +
        m_len(m->tab[0]) + 20));
        m->path_cmd[i] = m_cpy(m->path_cmd[i], m->path[i]);
        m->path_cmd[i] = my_strcat(m->path_cmd[i], "/");
        m->path_cmd[i] = my_strcat(m->path_cmd[i], m->tab[0]);
        if (access(m->path_cmd[i], X_OK) == 0
        && access(m->path_cmd[i], F_OK) == 0) {
            my_exec(m->path_cmd[i], m->env, ret, m);
            return (1);
        }
    }
    return (0);
}

int path_cmd2(my_env_t *m, int *ret)
{
    m->path_cmd = malloc(sizeof(char *) * (tab_len(m->path) + 20));
    for (int i = 0; m->path[i] != 0; i += 1) {
        m->path_cmd[i] = malloc(sizeof(char) * (m_len(m->path[i]) +
        m_len(m->tab[0]) + 20));
        m->path_cmd[i] = m_cpy(m->path_cmd[i], m->path[i]);
        m->path_cmd[i] = my_strcat(m->path_cmd[i], "/");
        m->path_cmd[i] = my_strcat(m->path_cmd[i], m->tab[0]);
        if (access(m->path_cmd[i], X_OK) == 0
        && access(m->path_cmd[i], F_OK) == 0) {
            my_exec2(m->path_cmd[i], m->env, ret, m);
            return (1);
        }
    }
    return (0);
}

char **get_path(char **env)
{
    char **path;
    for (int i = 0; env[i] != 0; i += 1) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' ||
        env[i][3] == 'H' && env[i][4] == '=')
            path = word_to_tab(env[i], ':', 5);
    }
    return (path);
}
