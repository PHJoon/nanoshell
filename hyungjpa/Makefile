SRC = test.c \
parsing_list_func.c parsing_list_main.c parsing_list_to_tree.c parsing_tree_check.c \
parsing_tree_func_1.c parsing_tree_func_2.c \
builtin_echo.c builtin_pwd.c builtin_exit.c builtin_env.c\

OBJ = ${SRC:.c=.o}

INCLUDE_LIBFT = -L ./libft -lft

INCLUDE = -I ./

INCLUDE_READLINE = -lreadline

LIBFT_DIR = ./libft/

NAME = a.out

all : ${NAME}

${NAME} : ${OBJ}
	make -C ${LIBFT_DIR} all
	cc ${INCLUDE} ${INCLUDE_LIBFT} ${INCLUDE_READLINE} $^ -o $@

clean :
	make -C ${LIBFT_DIR} clean
	rm -rf ${OBJ}

fclean : clean
	make -C ${LIBFT_DIR} fclean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re