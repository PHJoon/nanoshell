/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:53:51 by chanson           #+#    #+#             */
/*   Updated: 2023/02/16 19:22:58 by chanson          ###   ########.fr       */
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

void	link_tree(t_list *list, t_tree *tree, t_token *temp, int d)
{
	//show_list(list);
	if (tree->top == NULL)
	{
		tree->top = temp;
		tree->last = temp;
	}
	else if (d == 1)
	{
		tree->last->left = temp;
		tree->last = temp;
	}
	else if (d == 0)
	{
		tree->last->right = temp;
		tree->last = temp;
	}
}

static void	_make_tree(t_list *list, t_tree *tree, int d)
{
	int		i;
	int		idx;
	t_token	*temp;

	i = 0;
	if (list == NULL)
		return ;
	idx = find_top(list);
	if (idx == -1)
		return ;
	temp = list->first;
	while (i++ < idx)
		temp = temp->right;
	link_tree(list, tree, temp, d);
	temp->left->right = NULL;
	_make_tree(list, tree, 1);
	list->first = temp->right;
	list->first->left = NULL;
	_make_tree(list, tree, 0);
}

t_tree	*init_tree(char **temp)
{
	t_tree	*tree;
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	tree = (t_tree *)malloc(sizeof(t_tree));
	if (!list || !tree)
		return (FALSE);
	list->first = NULL;
	list->last = NULL;
	tree->top = NULL;
	tree->last = NULL;
	if (make_list(temp, list) == FALSE)
		return (FALSE);
	_make_tree(list, tree, 1);
	display_tree(tree->top, 's');
	return (tree);
}
