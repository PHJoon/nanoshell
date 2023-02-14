/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/14 16:22:30 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_node	*insert(t_node *root, char *str)
{
	if (root == NULL)
	{
		root = (t_node *)malloc(sizeof(t_node));
		root->right = NULL;
		root->left = NULL;
		root->str = str;
		root->type = check_av(str);
		return (root);
	}
	else
	{
		if (check_av(str) < root->type)
			root->left = insert(root->left, str);
		else
			root->right = insert(root->right, str);
	}
	return (root);
}

t_node	*min_node(t_node *root)
{
	t_node	*min;

	min = root;
	while (min->left != NULL)
		min = min->left;
	return (min);
}

t_node	*delete_else(t_node *root, t_node *tmproot, char *str)
{
	if (root->left != NULL && root->right != NULL)
	{
		tmproot = min_node(root->right);
		root->type = tmproot->type;
		root->right = delete(root->right, tmproot->str);
		return (root);
	}
	else
	{
		if (root->left == NULL)
			tmproot = root->right;
		else
			tmproot = root->left;
		free(root);
		return (tmproot);
	}
}

t_node	*delete(t_node *root, char *str)
{
	t_node	*tmproot;

	tmproot = NULL;
	if (root == NULL)
		return (NULL);
	if (check_av(str) < root->type)
		root->left = delete(root->left, str);
	else if (check_av(str) > root->type)
		root->right = delete(root->right, str);
	else
		return (delete_else(root, tmproot, str));
	return (root);
}

void	print(t_node *root)
{
	if (root == NULL)
	{
		printf("\n");
		return ;
	}
	printf("%s:%d ", root->str, root->type);
	print(root->left);
	print(root->right);
}

void	preorderprint(t_node *root)
{
	if (root == NULL)
		return ;
	printf("%s:%d ", root->str, root->type);
	print(root->left);
	print(root->right);
}
