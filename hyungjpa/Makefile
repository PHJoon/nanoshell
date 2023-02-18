NAME = test

SRCS_NAME = ./test \
			./utils/ft_split \
			./utils/ft_split_2 \
			./utils/ft_free_str \
			./utils/ft_strcjoin \
			./utils/ft_strsjoin \
			./utils/ft_strcpy \
			./utils/ft_strscmp \
			./syntax_check/syntax_check \
			./syntax_check/check_pattern \
			./syntax_check/check_str_valid \
			./syntax_tree/ast_ast_func \
			./syntax_tree/ast_list_func_1 \
			./syntax_tree/ast_list_func_2 \
			./syntax_tree/ast_main \
			./syntax_tree/ast_utils \
			./signal_handle/signal_handler \
			./builtin/builtin_echo \
			./builtin/builtin_env \
			./builtin/builtin_unset \
			./builtin/builtin_export \
			./builtin/builtin_utils \
			./display \




SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I ./includes/

RL_INCLUDE = -I/Users/hyungjpa/.brew/opt/readline/include/

RL_FLAGS = -L/Users/hyungjpa/.brew/opt/readline/lib

RL = -lreadline

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(RL_FLAGS) $(RL) $(RL_INCLUDE) $(INCLUDES) $(OBJS) -o $(NAME)

%.o : %.c
			@${CC} ${FLAGS} $(RL_INCLUDE) $(INCLUDES) -c $< -o $@


clean:		
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONEY:	all re fclean