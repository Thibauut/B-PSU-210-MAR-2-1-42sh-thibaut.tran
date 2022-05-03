/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_entry.c
*/

#include "../../include/my.h"

void my_simple_entry(my_env_t *m, int *ret)
{
    m->fd = 0;
    get_file_name(m, '<');
    m->file = clean_name(m->file);
    get_first_arg(m, '<');
    get_first_entry_arg(m, ret);
    get_entry_arg(m, ret);
    get_last_arg(m, '<');
    m->fd = open(m->file, O_RDWR);
    if (m->fd == -1) {
        my_putstr_error(m->file);
        my_putstr_error(": No such file or directory.\n");
        exit(1);
    }
    m->save = dup(STDIN_FILENO);
    m->verif_dup == 1;
    dup2(m->fd, STDIN_FILENO);
    m->tab = word_to_tab(m->first_arg, ' ', 0);
    m->path = get_path(m->env);
    check_cmd2(m->first_arg, m, ret);
    close(m->fd);
}

void my_double_entry(my_env_t *m, int *ret)
{
    get_first_arg(m, '<');
    get_file_name_double(m, '<');
    m->file = clean_name(m->file);
    get_last_arg_double(m, '<');
}

char *my_entry(my_env_t *m, int *ret, int i)
{
    if (m->line[i] == '<' && m->line[i + 1] != '<') {
        my_simple_entry(m, ret);
        return (m->new_line);
    }
    if (m->line[i] == '<' && m->line[i + 1] == '<') {
        my_double_entry(m, ret);
        return (m->new_line);
    }
}
