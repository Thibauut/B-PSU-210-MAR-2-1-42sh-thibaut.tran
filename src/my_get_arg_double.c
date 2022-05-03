/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_get_arg_double.c
*/

#include "../include/my.h"

int check_limit_double(my_env_t *m, int i, int j)
{
    for (; m->line[i] != '\0'; i += 1) {
        if (m->line[i] == '>' || double) {
            my_putstr_error("Ambiguous output redirect.\n");
            exit(EXIT_FAILURE);
        }
        if (m->line[i] == '|')
            return (1);
        if (m->line[i] == ';')
            return (1);
        m->file[j] = m->line[i];
        j += 1;
    }
    return (0);
}

void get_file_name_double(my_env_t *m, char c)
{
    int i = 0, j = 0, verif = 0;
    m->file = malloc(sizeof(char) * (my_strlen(m->line) + 1));
    for (; m->line[i] != c; i += 1);
    for (i += 2; m->line[i] == ' '; i += 1);
    if (c == '>' || c == '<') {
        if (check_limit_name(m, i, j) == 1)
            return;
    }
}

int check_limit_last_double(my_env_t *m, int i, int j)
{
    for (; m->line[i] != '\0'; i += 1) {
        if (m->line[i] == '>' || double) {
            my_putstr_error("Ambiguous output redirect.\n");
            exit(EXIT_FAILURE);
        }
        if (m->line[i] == '|')
            break;
        if (m->line[i] == ';')
            break;
    }
    return (i);
}

void get_last_arg_double(my_env_t *m, char c)
{
    m->new_line = malloc(sizeof(char) * (my_strlen(m->line) + 1));
    int i = 0, j = 0, k = 0, verif = 0;
    for (; m->line[i] != c; i += 1);
    for (i += 2; m->line[i] == ' '; i += 1);
    if (c == '>' || c == '<') {
        i = check_limit_last_double(m, i, j);
        for (i += 1; m->line[i] == ' '; i += 1);
    }
    for (; m->line[i] != '\0'; i += 1) {
        m->new_line[j] = m->line[i];
        j += 1;
    }
    m->new_line[j] = '\0';
}
