NAME = test

SRCS_NAME =  ./test \
		./utils/ft_split \
		./utils/ft_split_2 \
		./utils/ft_free_str \
		./utils/ft_strcjoin \
		./utils/ft_strsjoin \
		./utils/ft_strcpy \
		./utils/ft_strscmp \
		./utils/display \
		./utils/ft_strstr \
		./utils/ft_strtrim \
		./utils/ft_str_change \
		./utils/ft_strlen \
		./utils/ft_itoa \
		./utils/ft_str_find_c \
		./utils/ft_strcpy_index \
		./utils/ft_strfind \
		./utils/ft_strinsert \
		./parsing/syntax_check/syntax_check \
		./parsing/syntax_check/check_pattern \
		./parsing/syntax_check/check_str_valid \
		./parsing/tree/make_tree \
		./parsing/tree/decide_type \
		./parsing/tree/make_list \
		./parsing/tree/add_node_to_tree \
		./execute/pipe/pipe \
		./execute/heredoc/heredoc \
		./execute/heredoc/heredoc_cnt \
		./execute/heredoc/heredoc_env \
		./get_next_line/get_next_line \
		./get_next_line/get_next_line_utils \

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror -g3

LDFLAGS = -L/Users/chanson/.brew/opt/readline/lib -lreadline

CPPFLAGS = -I/Users/chanson/.brew/opt/readline/include

all:		$(NAME)
######################################################### srcs objs로 바바꾸꾸기
$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(LDFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

%.o : %.c
			@$(CC) $(FLAGS) $(CPPFLAGS) -c $< -o $@

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	all re fclean