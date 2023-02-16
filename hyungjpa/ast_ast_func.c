/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:35:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 13:35:07 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

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

int	check_type_place(t_node *head, int type, int *type_pos)
{
	int		i;
	int		pos_tmp;
	t_node	*tmp;

	i = 0;

	pos_tmp = node_size(head) - 1;
	tmp = head;
	while (tmp)
	{
		if (tmp->type == type)
			pos_tmp = i;
		i++;
		tmp = tmp->next;
	}
	if (*type_pos == pos_tmp)
		return (1);
	*type_pos = pos_tmp;
	return (0);
}

void	inorderprint(t_ast *root)
{
	if (root == NULL)
		return ;
	inorderprint(root->left);
	while (root->node)
	{
		printf("%s : %d\n", root->node->data, root->node->type);
		root->node = root->node->next;
	}
	inorderprint(root->right);
}
