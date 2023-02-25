/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:29:35 by chanson           #+#    #+#             */
/*   Updated: 2023/02/25 15:59:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.h"

static int	heredoc_cmp_limit(char *str, char *limit)
{
	char	*temp;

	temp = NULL;
	temp = ft_strcpy(limit);
	temp = ft_strcjoin(temp, '\n');
	if (ft_strscmp(str, temp) == TRUE)
	{
		free(temp);
		return (TRUE);
	}
	free(temp);
	return (FALSE);
}

static void	heredoc_fill(t_tree *tree, char *limit)
{
	char	*temp;
	int		index;

	while (1)
	{
		write(1, "here_doc> ", 10);
		temp = get_next_line(0);
		if (temp == 0)
			break ;
		if (heredoc_cmp_limit(temp, limit) == TRUE)
		{
			free(temp);
			break ;
		}
		index = ft_str_find_c(temp, '$');
		if (index != -1)
			temp = change_env(tree->envp_val, temp);
		write(tree->infile, temp, ft_strlen(temp));
		free(temp);
		temp = NULL;
	}
}

int	ft_heredoc(t_tree *tree, char *limit)
{
	char		*temp;
	char		*name;
	static int	index;

	name = NULL;
	name = ft_strstr(name, "heredoc");
	temp = ft_itoa(index);
	name = ft_strstr(name, temp);
	free(temp);
	tree->infile = open(name, O_WRONLY | O_CREAT, 0644);
	if (tree->infile < 0)
	{
		perror("infile not found");
		free (name);
		return (-1);
	}
	heredoc_fill(tree, limit);
	close(tree->infile);
	tree->here_documets[index] = name;
	index++;
	return (index);
}

void	execute_heredoc(t_token *node, t_tree *tree, char c)
{
	int	cnt;

	if (node == NULL)
		return ;
	if (ft_strscmp(node->val, "<<") == TRUE)
	{
		tree->here_doc += 1;
		node->val = ft_str_change(node->val, "<");
	}
	if (node->type == TK_STR && tree->here_doc > 0 && c == 'r')
	{
		cnt = ft_heredoc(tree, node->val);
		tree->here_doc -= 1;
		node->val = ft_str_change(node->val, tree->here_documets[cnt - 1]);
		return ;
	}
	if (node->type == TK_STR)
	{
		if (node->val[0] == '(' && node->val[1] != '(')
			mini_heredoc(node, tree);
		return ;
	}
	execute_heredoc(node->left, tree, 'l');
	execute_heredoc(node->right, tree, 'r');
}
