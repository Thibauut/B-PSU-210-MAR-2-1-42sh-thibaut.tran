/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_pipe3.c
*/

#include "../../include/my.h"

void get_pipe_arg(my_env_t *m, int *ret)
{
    int count = 0;
    for (int i = 0; m->line[i] != '\0'; i += 1) {
        if (m->line[i] == ';' || m->line[i] == '>'
        || m->line[i] == '|' || SIMPLE_REDIR2 || DOUBLE_REDIR2
        || SIMPLE_ENTRY2 || DOUBLE_ENTRY2) {
            count = 1;
            get_last_pipe(m, m->line[i]);
            break;
        }
    }
    if (count == 0)
        m->new_line = NULL;
}

void get_last_pipe_arg(my_env_t *m, char c)
{
    int i = 0, j = 0, verif = 0;
    m->file = malloc(sizeof(char) * (my_strlen(m->line) + 1));
    for (; m->line[i] != c; i += 1);
    for (i += 1; m->line[i] == ' '; i += 1);
    for (; m->line[i] != '\0'; i += 1) {
        if (m->line[i] == ';' || m->line[i] == '>'
        || m->line[i] == '|' || SIMPLE_REDIR2 || DOUBLE_REDIR2
        || SIMPLE_ENTRY2 || DOUBLE_ENTRY2)
            return;
        m->file[j] = m->line[i];
        j += 1;
    }
}

char *get_new_line(my_env_t *m, int *ret)
{
    int count = 0, i = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(m->new_line) + 1));
    char *tmp2 = malloc(sizeof(char) * (my_strlen(m->new_line) + 1));
    for (int j = 0; m->new_line[i] != '\0'; i += 1) {
        if (m->new_line[i] == ';' || m->new_line[i] == '>'
        || m->new_line[i] == '|' || SIMPLE_REDIR || DOUBLE_REDIR
        || SIMPLE_ENTRY || DOUBLE_ENTRY)
            count = 1;
        if (count == 1) {
            tmp[j] = m->new_line[i], j += 1;
        }
    }
    for (int k = 2, m = 0; tmp[k] != '\0'; k += 1) {
        tmp2[m] = tmp[k];
        m += 1;
    }
    return (tmp2);
}

char *get_new_line2(my_env_t *m, int *ret)
{
    int count = 0, i = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(m->new_line) + 1));
    char *tmp2 = malloc(sizeof(char) * (my_strlen(m->new_line) + 1));
    for (int j = 0; m->new_line[i] != '\0'; i += 1) {
        if (m->new_line[i] == ';' || m->new_line[i] == '>'
        || SIMPLE_REDIR || DOUBLE_REDIR
        || SIMPLE_ENTRY || DOUBLE_ENTRY)
            count = 1;
        if (count == 1) {
            tmp[j] = m->new_line[i], j += 1;
        }
    }
    for (int k = 2, m = 0; tmp[k] != '\0'; k += 1) {
        tmp2[m] = tmp[k];
        m += 1;
    }
    return (tmp2);
}
