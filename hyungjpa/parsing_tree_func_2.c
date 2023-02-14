/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tree_func_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:13:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/14 18:13:50 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print(t_node *root)
{
	if (root == NULL)
	{
		printf("\n");
		return ;
	}
	printf("%s:%d\n", root->str, root->type);
	print(root->left);
	print(root->right);
}

void	preorderprint(t_node *root)
{
	if (root == NULL)
		return ;
	printf("%s:%d\n", root->str, root->type);
	print(root->left);
	print(root->right);
}
