/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_exit.c
*/

#include "../../include/my.h"

int my_exit(my_env_t *m)
{
    if (m->tab[1] != NULL) {
        write(2, "exit\n", 5);
        exit(my_getnbr(m->tab[1]));
    } else {
        write(2, "exit\n", 5);
        exit (EXIT_SUCCESS);
    }
    return (0);
}
