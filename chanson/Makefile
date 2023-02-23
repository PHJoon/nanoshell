NAME = test

SRCS =  ./test.c \
		./utils/ft_split.c \
		./utils/ft_split_2.c \
		./utils/ft_free_str.c \
		./utils/ft_strcjoin.c \
		./utils/ft_strsjoin.c \
		./utils/ft_strcpy.c \
		./utils/ft_strscmp.c \
		./utils/display.c \
		./utils/ft_strstr.c \
		./utils/ft_strtrim.c \
		./utils/ft_str_change.c \
		./utils/ft_strlen.c \
		./utils/ft_itoa.c \
		./parsing/syntax_check/syntax_check.c \
		./parsing/syntax_check/check_pattern.c \
		./parsing/syntax_check/check_str_valid.c \
		./parsing/tree/make_tree.c \
		./parsing/tree/decide_type.c \
		./parsing/tree/make_list.c \
		./parsing/tree/add_node_to_tree.c \
		./execute/pipe.c \
		./execute/heredoc.c \
		./execute/heredoc_cnt.c \

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -lreadline -g3

LDFLAGS = -L/Users/chanson/.brew/opt/readline/lib

CPPFLAGS = -I/Users/chanson/.brew/opt/readline/include

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(LDFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	all re fclean