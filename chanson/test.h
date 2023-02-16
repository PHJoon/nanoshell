/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:58 by chanson           #+#    #+#             */
/*   Updated: 2023/02/16 19:23:24 by chanson          ###   ########.fr       */
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

typedef struct s_tree
{
	t_token		*top;
	t_token		*last;
}	t_tree;

typedef struct s_list
{
	t_token	*first;
	t_token	*last;
}	t_list;

// utils
char	*ft_strcjoin(char *s, char c);
char	**ft_strsjoin(char **str1, char *str);
void	ft_free_str(char **str);
char	**ft_split(char *s);
char	*ft_strcpy(char *str);
int		ft_split_and(char ***temp, char *str, int idx);
int		ft_split_par(char ***temp, char *str, int idx);
int		ft_strscmp(char *str1, char *str2);
void	show_list(t_list	*list);
void	display_str(char **str);
void	display_tree(t_token *root, char c);

//syntax_check
int		syntax_check(char **temp);
int		check_pattern(char **temp, int *type_list, int idx);
int		check_str_valid(char *str);

//tree
t_tree	*init_tree(char **temp);
int		make_list(char **temp, t_list *list);
int		decide_type(char *str);
#endif