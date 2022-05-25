/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_pipe.c
*/

#include "../../include/my.h"

void exec_pipe(my_env_t *m, int *ret, char *str)
{
    m->tab = word_to_tab(str, ' ', 0);
    m->path = get_path(m->env);
    check_cmd(str, m, ret);
}

void my_simple_pipe(my_env_t *m, int *ret)
{
    int pipefd[2], status = 0, pipefd_status = pipe(pipefd);
    init_pipe_arg(m, ret);
    pid_t pid = fork();
    pipe_error(pid, pipefd_status);
    if (pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        exec_pipe(m, ret, m->file);
        dup2(m->save_in, STDIN_FILENO);
        close(pipefd[0]);
        exit(0);
    } else {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        exec_pipe(m, ret, m->first_arg);
        dup2(m->save_out, STDOUT_FILENO);
        close(pipefd[1]);
        waitpid(pid, &status, 0);
    }
}

char *get_last_pipe_double(my_env_t *m, char c)
{
    char *str = malloc(sizeof(char) * (my_strlen(m->line) + 1));
    int i = 0, j = 0, k = 0, verif = 0;
    for (; m->line[i] != c; i += 1);
    for (i += 2; m->line[i] == ' '; i += 1);
    if (c == '>' || c == '<') {
        i = check_limit_last_double(m, i, j);
        for (i += 1; m->line[i] == ' '; i += 1);
    }
    for (; m->line[i] != '\0'; i += 1) {
        str[j] = m->line[i];
        j += 1;
    }
    str[j] = '\0';
    return (str);
}

void my_double_pipe(my_env_t *m, int *ret)
{
    get_first_arg(m, '|');
    get_last_arg_double(m, '|');
    m->tab = word_to_tab(m->first_arg, ' ', 0);
    m->path = get_path(m->env);
    get_file_name_double(m, '|');
    m->file = clean_name(m->file);
    if (check_cmd(m->first_arg, m, ret) == 84 || m->verif_and == 1) {
        m->tab = word_to_tab(m->file, ' ', 0);
        m->path = get_path(m->env);
    } else
        m->new_line = get_new_line2(m, ret);
}

char *my_pipe(my_env_t *m, int  *ret, int i)
{
    if (m->line[i] == '|' && m->line[i + 1] != '|') {
        my_simple_pipe(m, ret);
        return (m->new_line);
    }
    if (m->line[i] == '|' && m->line[i + 1] == '|') {
        my_double_pipe(m, ret);
        return (m->new_line);
    }
}
