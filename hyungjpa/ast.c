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
#include <string.h>

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
		head = add_back(head, strdup(temp[i]), type_list[i]);
		i++;
	}
	return (head);
}

t_node	*node_dup(t_node *head, int i)
{
	t_node	*dup;
	t_node	*tmp;

	dup = NULL;
	tmp = head;
	while (i && tmp)
	{
		dup = add_back(dup, strdup(tmp->data), tmp->type);
		tmp = tmp->next;
		i--;
	}
	return (dup);
}

int	node_size(t_node *head)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}