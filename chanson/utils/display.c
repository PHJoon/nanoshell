/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:48:49 by chanson           #+#    #+#             */
/*   Updated: 2023/02/17 17:13:05 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void	show_list(t_list	*list)
{
	t_token	*temp;
	int		i;

	if (!list)
	{
		printf("%s\n", NULL);
		return ;
	}
	temp = list->first;
	i = 0;
	printf("------------------display list------------------------\n\n");
	while (temp)
	{
		printf("list[%d]: %s	%d\n", i, temp->val, temp->type);
		i++;
		temp = temp->right;
	}
	printf("---------------------end------------------------------\n\n");
}

void	show_node_list(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		printf("%s ", temp->val);
		temp = temp->right;
	}
	printf("\n");
}

void	display_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
}

void	display_tree(t_token *root, char c)
{
	if (root == NULL)
		return ;
	if (root->type != TK_STR)
		printf("%s\n", root->val);
	else if (root->type == TK_STR)
	{
		show_node_list(root);
	}
	if (root->type == TK_STR || root == NULL)
		return ;
	display_tree(root->left, 'l');
	display_tree(root->right, 'r');
}
