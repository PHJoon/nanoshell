/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:53:51 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 17:50:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

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
	tree->cmd.envp_path = NULL;
	tree->cmd.cmd_head = NULL;
	tree->cmd.cmd_arr = NULL;
	tree->pipe_fd = NULL;
	tree->envp_val = NULL;
	tree->pid = NULL;
	tree->here_doc = 0;
	tree->here_doc_cnt = 0;
	tree->pipe_cnt = 0;
	tree->heredoc_idx = 0;
}

t_tree	*init_tree(char **temp, t_tree *tree)
{
	t_list	*list;
	t_token	*pre;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
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
