/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_ast_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:35:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

t_ast	*make_new_ast(t_node *res)
{
	t_ast	*new;

	if (res == NULL)
		return (NULL);
	new = (t_ast *)malloc(sizeof(t_ast));
	if (!new)
		return (0);
	new->node = res;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_ast	*ast_left_side(t_ast *root, t_node *left, int type)
{
	if (left)
	{
		if (!check_left(left, type))
			root->left = list_to_ast(root->left, left, type - 1);
		else
			root->left = list_to_ast(root->left, left, type);
	}
	return (root);
}

t_ast	*ast_right_side(t_ast *root, t_node *right, int type)
{
	if (right)
		root->right = list_to_ast(root->right, right, type - 1);
	return (root);
}
