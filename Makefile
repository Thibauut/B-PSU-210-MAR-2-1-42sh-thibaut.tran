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
		src/fix_dup.c				\
		src/builtin/my_setenv.c		\
		src/builtin/my_setenv2.c	\
		src/builtin/my_exit.c		\
		src/builtin/my_cd.c			\
		src/builtin/my_cd2.c		\
		src/builtin/my_env.c		\
		src/builtin/my_unsetenv.c	\
		src/symbol/my_pipe.c		\
		src/symbol/my_pipe2.c		\
		src/symbol/my_pipe3.c		\
		src/symbol/my_redirection.c	\
		src/symbol/my_entry.c		\
		src/symbol/my_andand.c		\
		src/symbol/my_semicolon.c

OBJ	=	$(SRC:.c=.o)

NAME	= 42sh

all	:	$(NAME)	$(SRC)

$(NAME)	:
	@printf "\x1B[1;34m\r[Compiling]               %$(SPACES)c\x1B[1;0m" ' '
	@sleep 1
	@gcc	-o $(NAME) $(SRC) -g3
	@printf "\x1B[1;32m\r[Compilation terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.5

clean :
	@rm	-f	$(OBJ)

fclean :
	@printf "\x1B[1;31m\r[Cleaning]                %$(SPACES)c\x1B[1;0m" ' '
	@sleep 1
	@rm	-f	$(NAME)
	@printf "\x1B[1;32m\r[Clean terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.5

re :	fclean	clean
	@printf "\x1B[1;33m\r[Recompiling]             %$(SPACES)c\x1B[1;0m" ' '
	@sleep 1
	@gcc	-o $(NAME) $(SRC) -g3
	@printf "\x1B[1;32m\r[Recompilation terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.5
