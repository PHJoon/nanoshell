/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:48:49 by chanson           #+#    #+#             */
/*   Updated: 2023/02/16 19:22:49 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void	show_list(t_list	*list)
{
	t_token	*temp;
	int		i;

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

static void	_display_tree(t_token *root)
{
	t_token	*temp;

	temp = root;
	while (temp->left)
		temp = temp->left;
	while (temp->right)
	{
		printf("%s ", temp->val);
		temp = temp->right;
	}
	printf("\n");
}

void	display_tree(t_token *root, char c)
{
	if (root->type == TK_STR)
	{
		printf("flag %c\n", c);
		_display_tree(root);
		return ;
	}
	printf("%s\n", root->val);
	display_tree(root->left, 'l');
	display_tree(root->right, 'r');
}
