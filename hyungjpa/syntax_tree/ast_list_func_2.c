/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:16:25 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 18:16:26 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

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

int	check_type_place(t_node *head, int type, int *type_pos)
{
	int		i;
	int		pos_tmp;
	t_node	*tmp;

	i = 0;
	pos_tmp = node_size(head) - 1;
	tmp = head;
	while (tmp)
	{
		if (tmp->type == type)
			pos_tmp = i;
		i++;
		tmp = tmp->next;
	}
	if (*type_pos == pos_tmp)
		return (1);
	*type_pos = pos_tmp;
	return (0);
}
