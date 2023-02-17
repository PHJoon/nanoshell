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

// list;
typedef struct s_node
{
	char			*data;
	int				type;
	struct s_node	*next;
}	t_node;

// ast;
typedef struct s_ast
{
	struct s_node	*node;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

// ast_ast_func.c
t_ast	*make_new_ast(t_node *res);
int		check_type_place(t_node *head, int type, int *type_pos);
void	inorderprint(t_ast *root);

// ast_list_func_1.c
t_node	*make_new(char *str, int t);
t_node	*add_back(t_node *head, char *str, int t);
t_node	*split_node(t_node *head, t_node **left, t_node **right, int i);
t_node	*node_dup(t_node *head, int i);

// ast_list_func_2.c
int		node_size(t_node *head);
int		check_left(t_node *head, int type);

// ast_main.c
t_node	*trans_to_list(char **temp);
t_ast	*list_to_ast(t_ast *root, t_node *head, int type);

// ast_utils.c
void	make_type_list(int *type_list, char **temp);
char	*ft_strdup(const char *s1);

#endif