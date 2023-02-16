/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:28:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 11:28:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include "test.h"

// list;
typedef struct s_node
{
	char			*data;
	int				type;
	struct s_node	*next;
}	t_node;

// tree;
typedef struct s_ast
{
	struct s_node	*node;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_ast_info
{
	struct s_ast	*root;
}	t_ast_info;

// ast.c
t_node	*trans_to_list(char **temp);
t_node	*node_dup(t_node *head, int i);
int	node_size(t_node *head);

// ast_2.c
void	make_type_list(int *type_list, char **temp);
t_node	*make_new(char *str, int t);
t_node	*add_back(t_node *head, char *str, int t);
char	**ft_split_substr(char **temp, size_t start, size_t end);

// ast_3.c
t_node	*split_node(t_node *head, t_node **left, t_node **right, int i);
t_ast	*list_to_ast(t_ast *root, t_node *head, int type);

void	print_list(t_node *node);

void	inorderprint(t_ast *root);
#endif