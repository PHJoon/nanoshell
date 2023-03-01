/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:58 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 17:13:19 by chanson          ###   ########.fr       */
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

# include "ast.h"
# include "signal_handler.h"
# include "builtin.h"
# include "utils.h"
# include "pipex.h"

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
}	t_tree;

// syntax_check
int		syntax_check(char **temp);
int		check_pattern(char **temp, int *type_list, int idx);
int		check_str_valid(char *str);
void	make_type_list(int *type_list, char **temp);

// display
void	display_node(t_node *head);
void	display_ast(t_ast *root);

char	**remove_quote(char **temp);
int		check_remove_quote(char *str);

char	**token_to_arr(t_token *cmd);
void	ft_error(char *str);

int		get_ird(char **temp);
int		get_ord(char **temp);
char	**cmd_get(char **temp);
void	display_str(char **str);
#endif