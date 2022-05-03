/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** fix_dup.c
*/

#include "../include/my.h"

void fix_dup(my_env_t *m)
{
    if (isatty(0) != 0) {
        dup2(1, STDOUT_FILENO);
        dup2(0, STDIN_FILENO);
    } else {
        dup2(2, STDOUT_FILENO);
        dup2(m->save, STDIN_FILENO);
    }
}
