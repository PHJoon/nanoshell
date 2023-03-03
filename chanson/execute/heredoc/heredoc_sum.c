/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:54:03 by chanson           #+#    #+#             */
/*   Updated: 2023/03/03 19:04:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	sum_string(char ***temp, t_token *node)
{
	t_token	*tmp_node;

	tmp_node = node;
	while (tmp_node)
	{
		*temp = ft_strsjoin(*temp, tmp_node->val);
		tmp_node = tmp_node->right;
	}
}

void	heredoc_sum(t_token *node, char ***temp)
{
	if (node == NULL)
		return ;
	heredoc_sum(node->left, temp);
	if (node->type == TK_STR)
	{
		sum_string(temp, node);
		return ;
	}
	else if (node->type != TK_STR)
		*temp = ft_strsjoin(*temp, node->val);
	heredoc_sum(node->right, temp);
}
