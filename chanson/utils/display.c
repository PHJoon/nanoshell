/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:48:49 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

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
		printf("list[%d]: %s	type: %d\n", i, temp->val, temp->type);
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
	{
		printf("%c: ", c);
		printf("%s\n", root->val);
	}
	else if (root->type == TK_STR)
	{
		printf("%c: ", c);
		show_node_list(root);
	}
	display_tree(root->left, 'l');
	if (root->type == TK_STR)
		return ;
	display_tree(root->right, 'r');
}

void	display_acc_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			printf("\\n");
		else if (str[i] > 32 && str[i] <= 126)
			printf("%c", str[i]);
		else
			printf("\\e");
		i++;
	}
	printf("\n");
}
