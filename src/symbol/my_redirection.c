/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_redirection.c
*/

#include "../../include/my.h"

char *clean_name(char *file)
{
    for (int i = 0; file[i] != '\0'; i += 1) {
        if (file[i] == ' ')
            file[i] = '\0';
    }
    return (file);
}

void my_simple_redir(my_env_t *m, int *ret)
{
    get_first_arg(m, '>');
    get_file_name(m, '>');
    m->file = clean_name(m->file);
    get_last_arg(m, '>');
    m->fd = open(m->file, O_CREAT | O_RDWR | O_TRUNC, 0777);
    m->save = dup(1);
    dup2(m->fd, 1);
    m->tab = word_to_tab(m->first_arg, ' ', 0);
    m->path = get_path(m->env);
    check_cmd(m->first_arg, m, ret);
    dup2(m->save, 1);
    close(m->fd);
}

void my_double_redir(my_env_t *m, int *ret)
{
    get_first_arg(m, '>');
    get_file_name_double(m, '>');
    m->file = clean_name(m->file);
    get_last_arg_double(m, '>');
    m->fd = open(m->file, O_CREAT | O_RDWR | O_APPEND, 0777);
    m->save = dup(1);
    dup2(m->fd, 1);
    m->tab = word_to_tab(m->first_arg, ' ', 0);
    m->path = get_path(m->env);
    check_cmd(m->first_arg, m, ret);
    dup2(m->save, 1);
    close(m->fd);
}

char *my_redirection(my_env_t *m, int  *ret, int i)
{
    if (m->line[i] == '>' && m->line[i + 1] != '>') {
        my_simple_redir(m, ret);
        return (m->new_line);
    }
    if (m->line[i] == '>' && m->line[i + 1] == '>') {
        my_double_redir(m, ret);
        return (m->new_line);
    }
    return (m->new_line);
}
