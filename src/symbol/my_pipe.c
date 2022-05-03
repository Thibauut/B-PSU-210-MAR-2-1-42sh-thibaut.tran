/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_pipe.c
*/

#include "../../include/my.h"

void get_pipe_arg(my_env_t *m, int *ret)
{
    int count = 0;
    for (int i = 0; m->line[i] != '\0'; i += 1) {
        if (m->line[i] == ';' || m->line[i] == '>'
        || m->line[i] == '|' || simple_redir2 || double_redir2
        || simple_entry2 || double_entry2) {
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
        || m->line[i] == '|' || simple_redir2 || double_redir2
        || simple_entry2 || double_entry2)
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
        || m->new_line[i] == '|' || simple_redir || double_redir
        || simple_entry || double_entry)
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

void exec_pipe(my_env_t *m, int *ret, char *str)
{
    m->tab = word_to_tab(str, ' ', 0);
    m->path = get_path(m->env);
    check_cmd(str, m, ret);
}

char *my_pipe(my_env_t *m, int  *ret)
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
    return (m->new_line);
}
