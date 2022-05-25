/*
** EPITECH PROJECT, 2021
** B-PSU-210-MAR-2-1-42sh-thibaut.tran
** File description:
** my_cd.c
*/

#include "../../include/my.h"

char *cd_neg(my_env_t *m, int *ret)
{
    char *str = NULL;
    if (m->old_pwd == NULL)
        return (my_itoa(1));
    else
        str = my_strdup(m->old_pwd);
    return (str);
}

char *cd_checker(my_env_t *m, int *ret)
{
    char *str = NULL;
    if (m->tab[0] != NULL && m->tab[1] == NULL)
        str = my_get_line(m->env, "HOME=");
    else if (m->tab[0] != NULL && m->tab[1][0] == '-')
        str = cd_neg(m, ret);
    else
        str = my_strdup(m->tab[1]);
    return (str);
}

int exec_cd(char *str, int *ret, my_env_t *m)
{
    if (access(str, F_OK) == 0) {
        m->old_pwd = my_get_line(m->env, "PWD=");
        chdir(str);
        m->refresh_pwd = getcwd(m->refresh_pwd, 4096);
    } else {
        *ret = 1, m->verif_and = 1;
        print_error(str, ": No such file or directory.\n");
        return (1);
    }
    return (0);
}

int cd(my_env_t *m, int *ret)
{
    char *str;
    if (m->tab[2] != NULL) {
        *ret = 1, m->verif_and = 1;
        return (print_error(m->tab[0], ": Too many arguments.\n"));
    }
    str = cd_checker(m, ret);
    DIR *is_dir = opendir(str);
    if (my_strcmp(str, my_itoa(1)) == 0) {
        *ret = 1, m->verif_and = 1;
        return (print_error("", ": No such file or directory.\n"));
    }
    if (is_dir == NULL && access(str, F_OK) == 0) {
        *ret = 1, m->verif_and = 1;
        return (print_error(str, ": Not a directory.\n"));
    }
    if (exec_cd(str, ret, m) == 1)
        return (0);
    pwd_tab(m), if_setenv_for_cd(m);
    return (0);
}
