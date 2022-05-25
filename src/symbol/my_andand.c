/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_andand.c
*/

#include "../../include/my.h"

char *my_andand(my_env_t *m, int *ret)
{
    get_first_arg(m, '&');
    get_last_arg_double(m, '&');
    m->tab = word_to_tab(m->first_arg, ' ', 0);
    m->path = get_path(m->env);
    if (check_cmd(m->first_arg, m, ret) == 84 || m->verif_and == 1)
        m->new_line = get_new_line(m, ret);
    return (m->new_line);
}
