/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:53:51 by chanson           #+#    #+#             */
/*   Updated: 2023/02/16 16:49:19 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void	display_list(t_list *list)
{
	t_token	*temp;

	temp = list->first;
	while (temp)
	{
		printf("%s %d\n", temp->val, temp->type);
		temp = temp->right;
	}
}

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
		if (type <= temp->type && temp->tyep != TK_STR)
		{
			if (temp->type >= TK_IRD && temp->type <= TK_ARD)
				type = 4;
			if (temp->type == TK_PIPE)
				type = 5;
			if (temp->type == TK_AND || temp->tyep == TK_OR)
				type = 7;
			index = i;
		}
		temp = temp->right;
		i++;
	}
	return (index);
}

void	link_tree(t_list *list, t_tree *tree, t_token *temp, int d)
{
	if (tree->top == NULL)
	{
		tree->top = temp;
		tree->last = temp;
	}
	else if (tree->last_left == NULL && d == 1)
		tree->last_left = temp;
	else if (tree->las)
}

void	_make_tree(t_list *list, t_tree *tree, int d)
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
	_make_tree(list, tree);
	list->first = temp->right;
	_make_tree(list, tree);
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
	return (NULL);
}
