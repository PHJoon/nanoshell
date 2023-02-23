/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:23:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 13:23:50 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	free_node(t_node *list)
{
	t_node	*tmp;
	t_node	*tmp_next;

	if (!list)
		return ;
	tmp = list;
	while (tmp)
	{
		free(tmp->data);
		tmp->data = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = tmp_next;
	}
}

void	free_ast(t_ast *ast)
{
	if (ast == NULL)
		return ;
	free_ast(ast->left);
	ast->left = NULL;
	free_ast(ast->right);
	ast->right = NULL;
	free_node(ast->node);
	ast->node = NULL;
	free(ast);
}