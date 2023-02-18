/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:38:15 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/18 15:38:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

void	display_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%s : %d \n", tmp->data, tmp->type);
		tmp = tmp->next;
	}
}

void	display_ast(t_ast *root)
{
	t_ast	*tmp;

	tmp = root;
	if (tmp == NULL)
		return ;
	display_node(tmp->node);
	display_ast(tmp->left);
	display_ast(tmp->right);
}
