##
## EPITECH PROJECT, 2021
## B-PSU-210-MAR-2-1-42sh-thibaut.tran
## File description:
## Makefile
##

SRC	=	42sh.c						\
		src/my_func.c				\
		src/my_func2.c				\
		src/my_func3.c				\
		src/my_get_path.c			\
		src/my_exec.c				\
		src/my_error.c				\
		src/my_minishell.c			\
		src/my_get_arg.c			\
		src/my_get_arg2.c			\
		src/my_get_arg_double.c		\
		src/my_check_cmd.c			\
		src/my_tab_and_space.c		\
		src/fix_dup.c		\
		src/builtin/my_setenv.c		\
		src/builtin/my_setenv2.c	\
		src/builtin/my_exit.c		\
		src/builtin/my_cd.c			\
		src/builtin/my_cd2.c		\
		src/builtin/my_env.c		\
		src/builtin/my_unsetenv.c	\
		src/symbol/my_pipe.c		\
		src/symbol/my_pipe2.c		\
		src/symbol/my_redirection.c	\
		src/symbol/my_entry.c		\
		src/symbol/my_semicolon.c

GREEN        =    \033[1;32m

CYAN        =    \033[1;36m

YELLOW        =    \033[0;33m

NC            =    \033[0;0m

OBJ	=	$(SRC:.c=.o)

NAME	= 42sh

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc	-g $(OBJ) 	-o	$(NAME)
	@echo	-e	"[$(GREEN)COMPILED$(NC)]	\"$(CYAN)$@$(NC)\"	[$(GREEN)CREATED$(NC)]"

clean :
	rm	-f	*.o
	rm	-f	*~
	rm src/*.o
	rm src/builtin/*.o
	rm src/symbol/*.o

fclean :
	rm	-f	$(NAME)

re :	fclean	all	clean
