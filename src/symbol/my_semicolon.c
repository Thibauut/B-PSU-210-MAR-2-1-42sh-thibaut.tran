/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_semicolon.c
*/

#include "../../include/my.h"

char *my_semicolon(my_env_t *m, int *ret)
{
    get_first_arg(m, ';');
    get_last_arg(m, ';');
    m->tab = word_to_tab(m->first_arg, ' ', 0);
    m->path = get_path(m->env);
    check_cmd(m->first_arg, m, ret);
    return (m->new_line);
}
