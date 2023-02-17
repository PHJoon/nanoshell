/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:53:51 by chanson           #+#    #+#             */
/*   Updated: 2023/02/17 17:29:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	find_top(t_list *list)
{
	int		i;
	int		type;
	int		index;
	t_token	*temp;

	i = 0;
	index = -1;
	temp = list->first;
	type = temp->type;
	while (temp)
	{
		if (type <= temp->type && temp->type != TK_STR)
		{
			if (temp->type >= TK_IRD && temp->type <= TK_ARD)
				type = 1;
			if (temp->type == TK_PIPE)
				type = 5;
			if (temp->type == TK_AND || temp->type == TK_OR)
				type = 6;
			index = i;
		}
		temp = temp->right;
		i++;
	}
	return (index);
}

static void	link_tree(t_tree *tree, t_token *temp, int d, t_token **pre)
{
	if (tree->top == NULL)
	{
		tree->top = temp;
		tree->last = temp;
	}
	else if (d == 1)
	{
		printf("1. %s %s\n", tree->last->val, temp->val);
		tree->last->left = temp;
		tree->last = temp;
	}
	else
	{
		printf("0. %s %s\n", (*pre)->val, temp->val);
		(*pre)->right = temp;
		tree->last = temp;
	}
}

static void	link_tree_last(t_list *list, t_tree *tree, int d, t_token **pre)
{
	t_token	*temp;

	temp = list->first;
	while (temp->left)
		temp = temp->left;
	if (d == 1)
	{
		printf("last: 1. %s %s\n", tree->last->val, temp->val);
		tree->last->left = temp;
	}
	else
	{
		printf("last: 0. %s %s\n", (*pre)->val, temp->val);
		(*pre)->right = temp;
	}
}

static void	_make_tree(t_list *list, t_tree *tree, int d, t_token **pre)
{
	int		i;
	int		idx;
	t_token	*temp;

	i = 0;
	if (list->first == NULL)
		return ;
	idx = find_top(list);
	if (tree->top == NULL && idx == -1)
	{
		tree->top = list->first;
		return ;
	}
	if (idx == -1)
	{
		link_tree_last(list, tree, d, pre);
		return ;
	}
	temp = list->first;
	while (i++ < idx)
		temp = temp->right;
	link_tree(tree, temp, d, pre);
	if (temp->left == NULL)
		list->first = NULL;
	else if (temp->left->right != NULL)
		temp->left->right = NULL;
	_make_tree(list, tree, 1, pre);
	*pre = temp;
	list->first = temp->right;
	if (list->first != NULL)
		list->first->left = NULL;
	_make_tree(list, tree, 0, pre);
}

t_tree	*init_tree(char **temp)
{
	t_tree	*tree;
	t_list	*list;
	t_token	*pre;

	list = (t_list *)malloc(sizeof(t_list));
	tree = (t_tree *)malloc(sizeof(t_tree));
	if (!list || !tree)
		return (FALSE);
	list->first = NULL;
	list->last = NULL;
	tree->top = NULL;
	tree->last = NULL;
	pre = NULL;
	if (make_list(temp, list) == FALSE)
		return (FALSE);
	show_list(list);
	_make_tree(list, tree, 1, &pre);
	tree->list = list;
	display_tree(tree->top, 's');
	system("leaks test");
	return (tree);
}
