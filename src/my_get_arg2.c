/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_get_arg2.c
*/

#include "../include/my.h"

void get_first_entry_arg(my_env_t *m, int  *ret)
{
    m->new_line = malloc(sizeof(char) * (my_strlen(m->line) + 1));
    int i = 0, j = 0;
    for (; m->line[i] != '\0'; i += 1) {
        m->new_line[j] = m->line[i];
        j += 1;
    }
    m->new_line = tab_to_space(m->new_line);
    m->new_line = rm_extra_spaces(m->new_line);
}

void get_last_entry_arg(my_env_t *m, char c)
{
    m->new_line = malloc(sizeof(char) * (my_strlen(m->line) + 1));
    int i = 0, j = 0, k = 0, verif = 0;
    for (; m->line[i] != c; i += 1);
    for (i += 1; m->line[i] == ' '; i += 1);
    if (c == '>' || c == '<') {
        i = check_limit_last(m, i, j);
        for (i += 1; m->line[i] == ' '; i += 1);
    }
    for (; m->line[i] != '\0'; i += 1) {
        m->new_line[j] = m->line[i];
        j += 1;
    }
    m->new_line[j] = '\0';
}

void get_entry_arg(my_env_t *m, int *ret)
{
    int count = 0;
    for (int i = 0; m->line[i] != '\0'; i += 1) {
        if (m->line[i] == ';' || m->line[i] == '|') {
            count = 1;
            get_last_entry_arg(m, m->line[i]);
            break;
        }
    }
    if (count == 0)
        m->new_line = NULL;
}
