NAME = test

SRCS_NAME = ./test \
			./utils/ft_free_str \
			./utils/ft_str_size \
			./utils/ft_strchr \
			./utils/ft_strcjoin \
			./utils/ft_strdup \
			./utils/ft_strlen \
			./utils/ft_strrchr \
			./utils/ft_strscmp \
			./utils/ft_strsjoin \
			./utils/syntax_ft_split_1 \
			./utils/syntax_ft_split_2 \
			./utils/syntax_ft_split_3 \
			./get_next_line/get_next_line_utils \
			./get_next_line/get_next_line \
			./syntax_check/syntax_check \
			./syntax_check/check_pattern \
			./syntax_check/check_str_valid \
			./syntax_tree/ast_ast_func \
			./syntax_tree/ast_free \
			./syntax_tree/ast_list_func_1 \
			./syntax_tree/ast_list_func_2 \
			./syntax_tree/ast_main \
			./signal_handle/signal_handler \
			./builtin/builtin_main \
			./builtin/builtin_cd_1 \
			./builtin/builtin_cd_2 \
			./builtin/builtin_echo \
			./builtin/builtin_env_1 \
			./builtin/builtin_env_2 \
			./builtin/builtin_exit \
			./builtin/builtin_export_1 \
			./builtin/builtin_export_2 \
			./builtin/builtin_pwd \
			./builtin/builtin_unset \
			./display \
			./utils/pipex_ft_strjoin \
			./utils/pipex_str_cp \
			./utils/ft_strtrim \
			./remove_quote \
			./utils/ft_strcpy_index \
			./heredoc \
			./utils/ft_isalnum \
			./utils/ft_isalpha \
			./builtin/builtin_error \





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
			@$(CC) $(FLAGS) $(RL_FLAGS) $(RL) $(RL_INCLUDE) $(INCLUDES) $(SRCS) -o $(NAME)

%.o : %.c
			@$(CC) $(FLAGS) $(RL_INCLUDE) $(INCLUDES) -c $< -o $@


clean:		
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONEY:	all re fclean