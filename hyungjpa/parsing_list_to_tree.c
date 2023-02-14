/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:09:25 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/14 18:09:26 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_node	*list_to_tree(char *str)
{
	t_lst_info	*info;
	t_node		*root;
	t_node		*root_tmp;

	root_tmp = NULL;
	info = rl_to_list(str);
	if (info->head)
	{
		root_tmp = insert(root_tmp, info->head->data);
		root = root_tmp;
		info->head = info->head->next;
	}
	while (info->head)
	{
		root_tmp = insert(root_tmp, info->head->data);
		if (check_str(info->head->data) == 3)
			root_tmp = root_tmp->right;
		info->head = info->head->next;
	}
	return (root);
}
