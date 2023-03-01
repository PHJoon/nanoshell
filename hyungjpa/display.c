/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:38:15 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/include/test.h"

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

void	display_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
}