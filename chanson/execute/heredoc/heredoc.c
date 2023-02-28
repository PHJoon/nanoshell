/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:29:35 by chanson           #+#    #+#             */
/*   Updated: 2023/02/28 15:24:08 by chanson          ###   ########.fr       */
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

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	while (1)
	{
		temp = readline("heredoc> ");
		if (temp == 0)
			break ;
		temp = ft_strcjoin(temp, '\n');
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
	exit(1);
}

int	ft_heredoc(t_tree *tree, char *limit)
{
	char		*temp;
	char		*name;
	static int	index;
	pid_t		pid;

	name = NULL;
	name = ft_strstr(name, "heredoc");
	temp = ft_itoa(index);
	name = ft_strstr(name, temp);
	free(temp);
	tree->infile = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tree->infile < 0)
		ft_error("file error\n");
	tree->here_documets[index] = name;
	printf("limit: %s\n", limit);
	pid = fork();
	if (pid < 0)
		ft_error("fork error\n");
	if (pid == 0)
	{
		heredoc_fill(tree, limit);
		close(tree->infile);
	}
	waitpid(pid, 0, 0);
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
