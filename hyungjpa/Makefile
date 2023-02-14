SRC = sigtest.c \
tree_check.c tree_func.c \
builtin_echo.c builtin_pwd.c builtin_exit.c \
line_list_1.c line_list_2.c

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