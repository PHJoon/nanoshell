NAME = test

SRCS =  ./test.c \
		./utils/ft_split.c \
		./utils/ft_free_str.c \
		./utils/ft_strcjoin.c \
		./utils/ft_strsjoin.c \
		./utils/ft_strcpy.c \

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