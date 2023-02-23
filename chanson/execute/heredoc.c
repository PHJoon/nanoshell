/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:29:35 by chanson           #+#    #+#             */
/*   Updated: 2023/02/23 13:55:31 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

static int	ft_heredoc(t_tree *tree, char *limit)
{
	char		*temp;
	char		*name;
	static int	index;

	name = NULL;
	printf("limit: %s\n", limit);
	name = ft_strstr(name, "heredoc");
	temp = ft_itoa(index);
	name = ft_strstr(name, temp);
	free(temp);
	tree->infile[index] = open(name, O_WRONLY | O_CREAT, 0644);
	if (tree->infile[index] < 0)
	{
		perror("infile not found");
		free (name);
		return (-1);
	}
	while (1)
	{
		temp = readline("here_doc> ");
		if (temp == 0)
			break ;
		if (ft_strscmp(temp, limit) == TRUE)
		{
			free(temp);
			break ;
		}
		write(tree->infile[index], temp, ft_strlen(temp));
		free(temp);
	}
	close(tree->infile[index]);
	tree->here_documets[index] = name;
	index++;
	return (index);
}

void	execute_heredoc(t_token *node, t_tree *tree, char c)
{
	int	cnt;

	if (node != NULL)
		printf("node val: %s\n", node->val);
	if (node == NULL)
		return ;
	if (ft_strscmp(node->val, "<<") == TRUE)
	{
		tree->here_doc = TRUE;
		node->val = ft_str_change(node->val, "<");
	}
	if (node->type == TK_STR && tree->here_doc == TRUE && c == 'r')
	{
		cnt = ft_heredoc(tree, node->val);
		tree->here_doc = FALSE;
		printf("hello: %s\n", node->val);
		free(node->val);
		node->val = ft_str_change(node->val, tree->here_documets[cnt - 1]);
		printf("%s\n", node->val);
		return ;
	}
	if (node->type == TK_STR)
		return ;
	execute_heredoc(node->left, tree, 'l');
	execute_heredoc(node->right, tree, 'r');
}
