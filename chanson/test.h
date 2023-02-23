/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:58 by chanson           #+#    #+#             */
/*   Updated: 2023/02/23 16:29:30 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "get_next_line.h"

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
char	**ft_strsjoin(char **str1, char *str);
char	**ft_split(char *s);
int		ft_split_and(char ***temp, char *str, int idx);
int		ft_split_par(char ***temp, char *str, int idx);
int		ft_strscmp(char *str1, char *str2);
int		ft_strlen(char *str);
int		ft_str_find_c(char *str, char c);
void	show_list(t_list	*list);
void	display_str(char **str);
void	display_tree(t_token *root, char c);
void	show_node_list(t_token *token);
void	ft_free_str(char **str);

//parsing/syntax_check
int		syntax_check(char **temp);
int		check_pattern(char **temp, int *type_list, int idx);
int		check_str_valid(char *str);

//parsing/tree
t_tree	*init_tree(char **temp);
t_token	*add_node(t_list *list, t_tree *tree, int d, t_token **pre);
int		make_list(char **temp, t_list *list);
int		decide_type(char *str);

//execute
int		count_pipe(char **temp);
void	cnt_heredoc(t_token *node, t_tree *tree);
void	execute_heredoc(t_token *node, t_tree *tree, char c);
#endif