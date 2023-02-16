/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:35:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 13:35:07 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	print_list(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp)
	{
		printf("%s : %d\n", tmp->data, tmp->type);
		tmp = tmp->next;
	}
}

t_node	*split_node(t_node *head, t_node **left, t_node **right, int i)
{
	t_node	*tmp;
	t_node	*res;
	int		cnt;

	tmp = head;
	cnt = 0;
	while (cnt < i)
	{
		tmp = tmp->next;
		cnt++;
	}
	*left = node_dup(head, i);
	*right = node_dup(tmp->next, node_size(tmp->next));
	res = node_dup(tmp, 1);
	// free node(head);
	return (res);
}

t_ast	*make_new_ast(t_node *res)
{
	t_ast	*new;

	new = (t_ast *)malloc(sizeof(t_ast));
	if (!new)
		return (0);
	new->node = res;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	check_left(t_node *head, int type)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->type == type)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_ast	*list_to_ast(t_ast *root, t_node *head, int type)
{
	t_node	*tmp;
	t_node	*left;
	t_node	*right;
	t_node	*res;
	int		i;
	int		break_p;

	i = 0;
	tmp = head;
	printf("%d\n", type);
	if (type == 0)
		return (0);
	break_p = node_size(head) - 1;
	while (tmp)
	{
		if (tmp->type == type)
			break_p = i;
		i++;
		tmp = tmp->next;
	}
	res = split_node(head, &left, &right, break_p);
	root = make_new_ast(res);
	if (left)
	{
		if (check_left(left, type))
			type--;
		root->left = list_to_ast(root->left, left, type);
	}
	if (right)
		root->right = list_to_ast(root->right, right, type - 1);
	return (root);
}

void	inorderprint(t_ast *root)
{
	if (root == NULL)
		return ;
	inorderprint(root->left);
	while (root->node)
	{
		printf("%s : %d\n", root->node->data, root->node->type);
		root->node = root->node->next;
	}
	inorderprint(root->right);
}