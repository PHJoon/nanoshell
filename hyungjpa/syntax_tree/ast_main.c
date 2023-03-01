/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:26:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

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
		head = add_back(head, ft_strcpy(temp[i]), type_list[i]);
		i++;
	}
	free(type_list);
	return (head);
}

t_ast	*list_to_ast(t_ast *root, t_node *head, int type)
{
	t_node	*left;
	t_node	*right;
	t_node	*res;
	int		type_pos;

	type_pos = node_size(head) - 1;
	if (type == 0 || type_pos == 0)
	{
		res = node_dup(head, node_size(head));
		return (make_new_ast(res));
	}
	if (check_type_place(head, type, &type_pos))
		return (list_to_ast(root, head, type - 1));
	res = split_node(head, &left, &right, type_pos);
	root = make_new_ast(res);
	root = ast_left_side(root, left, type);
	root = ast_right_side(root, right, type);
	free_node(left);
	free_node(right);
	return (root);
}
