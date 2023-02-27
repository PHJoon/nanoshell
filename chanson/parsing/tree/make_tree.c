/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:53:51 by chanson           #+#    #+#             */
/*   Updated: 2023/02/27 19:45:07 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.h"

static void	_make_tree(t_list *list, t_tree *tree, int d, t_token **pre)
{
	t_token	*temp;

	if (list->first == NULL)
		return ;
	temp = add_node(list, tree, d, pre);
	if (temp == FALSE)
		return ;
	_make_tree(list, tree, 1, pre);
	*pre = temp;
	list->first = temp->right;
	if (list->first != NULL)
		list->first->left = NULL;
	_make_tree(list, tree, 0, pre);
}

static void	set_tree(t_tree *tree)
{
	tree->top = NULL;
	tree->last = NULL;
	tree->here_documets = NULL;
	tree->here_doc = 0;
	tree->here_doc_cnt = 0;
	tree->pipe_cnt = 0;
	tree->infile = 0;
	tree->outfile = 0;
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
	set_tree(tree);
	pre = NULL;
	if (make_list(temp, list) == FALSE)
		return (FALSE);
	_make_tree(list, tree, 1, &pre);
	free(list);
	list = NULL;
	return (tree);
}
