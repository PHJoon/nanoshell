/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:58 by chanson           #+#    #+#             */
/*   Updated: 2023/02/28 16:20:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define FALSE 0
# define TRUE 1
# define PARENT 4
# define CHILD 5
# define HEREDOC 6

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

typedef struct s_tree
{
	t_token		*top;
	t_token		*last;
	int			pipe_cnt;
	int			here_doc;
	int			mini_here_doc;
	int			here_doc_cnt;
	int			infile;
	int			outfile;
	char		**here_documets;
	char		**envp_val;
}	t_tree;

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
char	**ft_strsjoin(char **str1, char *str);
char	**ft_split(char *s);
int		ft_split_and(char ***temp, char *str, int idx);
int		ft_split_par(char ***temp, char *str, int idx);
int		ft_strscmp(char *str1, char *str2);
int		ft_strlen(char *str);
int		ft_str_find_c(char *str, char c);
int		ft_atoi(const char *str);
int		ft_split_quote(char ***temp, char *str, int idx);
int		ft_split_redirection(char ***temp, char *str, int idx);
int		ft_split_pipe(char ***temp, char *str, int idx);
void	ft_free_str(char **str);
void	ft_error(char *str);

// utils->display.c
void	show_list(t_list	*list);
void	display_str(char **str);
void	display_tree(t_token *root, char c);
void	display_acc_str(char *str);
void	show_node_list(t_token *token);

//parsing/syntax_check
int		syntax_check(char **temp);
int		check_pattern(char **temp, int *type_list, int idx);
int		check_str_valid(char *str);
int		syntax_err_check(char **temp);

//parsing/tree
t_tree	*init_tree(char **temp);
t_token	*add_node(t_list *list, t_tree *tree, int d, t_token **pre);
int		make_list(char **temp, t_list *list);
int		decide_type(char *str);

//execute/pipe
int		count_pipe(char **temp);

//execute/heredoc
void	cnt_heredoc(t_token *node, t_tree *tree);
void	execute_heredoc(t_token *node, t_tree *tree, char c);
void	*change_env(char **envp, char *temp);
void	mini_heredoc(t_token *node, t_tree *tree);
int		ft_heredoc(t_tree *tree, char *limit);

//signal
void	on_off_catch_signals(int on_off);
void	parent_sig_handler(int signo);
void	do_signal_handle(int status);
void	signal_sigterm(char *str);
void	child_signal_handle(void);

#endif