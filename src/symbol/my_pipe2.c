/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_pipe2.c
*/

#include "../../include/my.h"

void pipe_error(pid_t pid, int pipefd)
{
    if (pid == -1) {
        perror("fork.\n");
        exit(EXIT_FAILURE);
    }
    if (pipefd == -1) {
        perror("pipe.\n");
        exit(EXIT_FAILURE);
    }
}

void get_last_pipe(my_env_t *m, char c)
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

void init_pipe_arg(my_env_t *m, int *ret)
{
    get_last_pipe_arg(m, '|');
    get_first_arg(m, '|');
    get_first_entry_arg(m, ret);
    get_pipe_arg(m, ret);
    m->new_line = get_new_line(m, ret);
}
