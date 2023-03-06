/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:29:35 by chanson           #+#    #+#             */
/*   Updated: 2023/03/06 20:46:31 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

void	sig_heredoc_ctrl_c(int signo)
{
	(void)signo;
	g_signal_flag = 2;
	write(1, "\b", 1);
	// write(1, "heredoc> \n", 10);
	// write(1, "\b", 1);
	exit(130);
}

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

	g_signal_flag = 1;
	do_signal_handle(HEREDOC);
	while (1)
	{
		temp = readline("heredoc> ");
		if (temp == NULL || g_signal_flag == 2)
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
	exit(0);
}

int	ft_heredoc(t_tree *tree, char *limit)
{
	char		*temp;
	char		*name;
	int			index;
	pid_t		pid;

	name = NULL;
	name = ft_strstr(name, "heredoc");
	temp = ft_itoa(tree->heredoc_idx);
	name = ft_strstr(name, temp);
	free(temp);
	tree->infile = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tree->infile < 0)
		ft_error("file error\n");
	tree->here_documets[tree->heredoc_idx] = name;
	pid = fork();
	if (pid < 0)
		ft_error("fork error\n");
	if (pid == 0)
		heredoc_fill(tree, limit);
	do_signal_handle(WAIT_CHILD);
	waitpid(pid, &tree->child_status, 0);
	tree->heredoc_idx++;
	index = tree->heredoc_idx;
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
