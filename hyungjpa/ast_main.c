/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_tree_ver_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:26:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 11:26:31 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_node	*trans_to_list(char **temp)
{
	int		*type_list;
	int		i;
	t_node	*head;

	i = 0;
	head = NULL;
	while (temp[i])
		i++;
	type_list = (int *)malloc(sizeof(int) * i);
	make_type_list(type_list, temp);
	i = 0;
	while (temp[i])
	{
		head = add_back(head, ft_strdup(temp[i]), type_list[i]);
		i++;
	}
	return (head);
}

t_ast	*list_to_ast(t_ast *root, t_node *head, int type)
{
	t_node	*left;
	t_node	*right;
	t_node	*res;
	int		type_pos;

	printf("%d\n", type);
	type_pos = node_size(head) - 1;
	if (type == 0)
		return (make_new_ast(head));
	if (check_type_place(head, type, &type_pos))
		return (list_to_ast(root, head, type - 1));
	res = split_node(head, &left, &right, type_pos);
	root = make_new_ast(res);
	if (left)
	{
		if (!check_left(left, type))
			root->left = list_to_ast(root->left, left, type - 1);
		else
			root->left = list_to_ast(root->left, left, type);
	}
	if (right)
		root->right = list_to_ast(root->right, right, type - 1);
	return (root);
}
