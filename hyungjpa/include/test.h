/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:58 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 17:49:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define FALSE 0
# define TRUE 1
# define READ 0
# define WRITE 1
# define PARENT	4
# define CHILD	5
# define WAIT_CHILD 6
# define HEREDOC 7

# define PIPE 1
# define N_FILE 2

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <dirent.h>

enum e_token
{
	TK_STR,
	TK_IRD,
	TK_ORD,
	TK_HRD,
	TK_ARD,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_LPT,
	TK_RPT,
	TK_INVALID,
	TK_EXPANDED_STR,
	TK_QUOTED_STR
};

typedef struct s_token
{
	char			*val;
	struct s_token	*left;
	struct s_token	*right;
	enum e_token	type;
}	t_token;

typedef struct s_list
{
	t_token	*first;
	t_token	*last;
}	t_list;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}	t_env;

typedef struct s_cmd
{
	char	*cmd_head;
	char	**cmd_arr;
	char	**envp_path;
}	t_cmd;

typedef struct s_tree
{
	t_token		*top;
	t_token		*last;
	t_cmd		cmd;
	int			pipe_cnt;
	int			here_doc;
	int			mini_here_doc;
	int			here_doc_cnt;
	int			infile;
	int			outfile;
	int			child_status;
	int			next_pipe_or_file;
	int			heredoc_idx;
	int			**pipe_fd;
	char		**here_documets;
	char		**envp_val;
	pid_t		*pid;
	t_env		*env_list;
	t_env		*export_list;
}	t_tree;

extern int	g_signal_flag;

// utils
char	*ft_strcjoin(char *s, char c);
char	*ft_str_change(char *old, char *new);
char	*ft_strcpy_index(char *str, int start, int end);
char	*ft_strcpy(char *str);
char	*ft_strstr(char *str_origin, char *str_new);
char	*ft_strtrim_couple(char *str, char c1, char c2);
char	*ft_strtrim(char *str, char c);
char	*ft_strtrim_couple_check(char *str, char c1, char c2);
char	*ft_itoa(int num);
char	*ft_strfind(char **strs, char *find);
char	*ft_strinsert(char *str, char *insert, int start, int end);
char	*fr_strdel_one(char *str, int index);
char	*str_find(char **strs, char *find);
char	*ft_strstr_no_free(char *str_origin, char *str_new);
char	*ft_strjoin(char *str1, char *str2);
char	**ft_strsjoin(char **str1, char *str);
char	**ft_strsjoin_2(char **str1, char *str);
char	**ft_split(char *s);
char	**ft_split_char(char *str, char c);
char	**remove_quote(char **temp);
int		ft_split_and(char ***temp, char *str, int idx);
int		ft_split_par(char ***temp, char *str, int idx);
int		ft_strscmp(char *str1, char *str2);
int		ft_strlen(char *str);
int		ft_str_find_c(char *str, char c);
int		ft_atoi(const char *str);
int		ft_split_quote(char ***temp, char *str, int idx);
int		ft_split_redirection(char ***temp, char *str, int idx);
int		ft_split_pipe(char ***temp, char *str, int idx);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strrchr(char *s, int c);
int		ft_strchr(const char *s, int c);
int		str_size(char **str);
int		check_remove_quote(char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
void	ft_free_str(char **str);
void	ft_error(char *str);
void	ft_free_tree(t_tree *tree);

//parsing/syntax_check
int		syntax_check(char **temp);
int		check_pattern(char **temp, int *type_list, int idx);
int		check_str_valid(char *str);
int		syntax_err_check(char **temp);

//parsing/tree
t_tree	*init_tree(char **temp, t_tree *tree);
t_token	*add_node(t_list *list, t_tree *tree, int d, t_token **pre);
int		make_list(char **temp, t_list *list);
int		decide_type(char *str);

//execute/pipe
int		count_pipe(char **temp);
int		get_ird(char **temp);
int		get_ord(char **temp);
char	**cmd_get(char **temp);
void	setting_pipe(t_tree *tree);
void	wait_pid(t_tree *tree);
void	cmd_check(t_tree *tree, char **cmd);
void	fork_first(t_tree *tree);
void	fork_mid(t_tree *tree, int index);
void	fork_last(t_tree *tree);
void	execute_pipe(char **temp, t_tree *tree);
void	execute_no_pipe(char **temp, t_tree *tree);
void	close_pipe_all(t_tree *tree);

//execute/heredoc
void	cnt_heredoc(t_token *node, t_tree *tree);
void	execute_heredoc(t_token *node, t_tree *tree, char c);
void	*change_env(char **envp, char *temp);
void	mini_heredoc(t_token *node, t_tree *tree);
int		ft_heredoc(t_tree *tree, char *limit);
void	heredoc_sum(t_token *node, char ***temp);

// execute/builtin
int		do_cd(t_tree *info);
void	cd_home(t_env *env_list);
int		check_dir(char *cwd_buf);
int		do_echo(t_tree *info);
int		do_env(t_tree *info);
char	**env_to_envp(t_env *env_list);
char	**envp_copy(char **envp);
t_env	*add_env_list(t_env *env_list, char *key, char *value);
t_env	*make_env_list(char **envp);
t_env	*sort_export_list(t_env *export_list);
t_env	*make_export_list(char **envp);
char	*find_path(t_tree *info);
int		do_exit(t_tree *info);
int		do_export(t_tree *info);
void	print_export(t_env *export_list);
int		valid_check(char *str);
int		do_pwd(t_tree *info);
int		do_unset(t_tree *info);
int		builtin(t_tree *info);
int		print_error_1(char *str);
int		print_error_2(char *str1, char *str2);
int		print_error_3(char *str1, char *str2, char *str3);

//signal
void	on_off_catch_signals(int on_off);
void	parent_sig_handler(int signo);
void	do_signal_handle(int status);
void	signal_sigterm(char *str);
void	child_signal_handle(void);

// utils->display.c
void	show_list(t_list	*list);
void	display_str(char **str);
void	display_tree(t_token *root, char c);
void	display_acc_str(char *str);
void	show_node_list(t_token *token);
void	display_list_envp(t_env *node);
void	display_tree_all(t_tree *tree);

// set_tree.c
t_tree	*tree_preset(char **envp);
t_tree	*tree_set_re(t_tree *tree);
// start_minishell.c
void	start_minishell(t_tree *tree);

// init_heredoc_and_pipe.c
void	_init_heredoc_and_pipe(t_tree *tree, char ***temp);
#endif