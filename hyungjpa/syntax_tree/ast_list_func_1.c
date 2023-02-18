/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:12:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 18:12:37 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

t_node	*make_new(char *str, int t)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->type = t;
	new->data = str;
	return (new);
}

t_node	*add_back(t_node *head, char *str, int t)
{
	t_node	*new;
	t_node	*tmp;

	new = make_new(str, t);
	tmp = head;
	if (head == NULL)
		head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (head);
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
	return (res);
}

t_node	*node_dup(t_node *head, int i)
{
	t_node	*dup;
	t_node	*tmp;

	dup = NULL;
	tmp = head;
	while (i && tmp)
	{
		dup = add_back(dup, ft_strdup(tmp->data), tmp->type);
		tmp = tmp->next;
		i--;
	}
	return (dup);
}
