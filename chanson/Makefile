NAME = test

SRCS =  ./test.c \
		./utils/ft_split.c \
		./utils/ft_split_2.c \
		./utils/ft_free_str.c \
		./utils/ft_strcjoin.c \
		./utils/ft_strsjoin.c \
		./utils/ft_strcpy.c \
		./utils/ft_strscmp.c \
		./syntax_check/syntax_check.c \
		./syntax_check/check_pattern.c \
		./syntax_check/check_str_valid.c \
		./tree/make_tree.c \
		./tree/decide_type.c \
		./tree/make_list.c \

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -lreadline -g3

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	all re fclean