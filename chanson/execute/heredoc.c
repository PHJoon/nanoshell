/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:29:35 by chanson           #+#    #+#             */
/*   Updated: 2023/02/23 16:56:07 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

static char	*change_env(char **envp, char *temp, int index)
{
	int		end;
	int		i;
	char	*str;
	char	*str2;

	i = index;
	while (temp[++i])
	{
		end = i;
		if (temp[i] == ' ' || temp[i] == '\'' || temp[i] == '\"')
			break ;
	}
	end--;
	str = ft_strcpy_index(temp, index + 1, end);
	printf("str: %s\n", str);
	str2 = ft_strfind(envp, str);
	printf("str2: %s\n", str2);
	free(str);
	if (str2 != NULL)
	{
		i = -1;
		while (str2[++i])
		{
			if (str2[i] == '=')
				break;
		}
		str = ft_strcpy_index(str2, i + 1, ft_strlen(str2));
		printf("strstr: %s\n", str);
		free(str2);
		str2 = ft_strinsert(temp, str, index, end + 1);
		printf("str2str2: %s\n", str2);
		free(str);
	}
	printf("final str2: %s\n", str2);
	return (str2);
}

static void	heredoc_fill(t_tree *tree, char *limit)
{
	char	*temp;
	int		index;
	char	*final;

	while (1)
	{
		write(1, "here_doc> ", 10);
		temp = get_next_line(0);
		if (temp == 0)
			break ;
		final = ft_strcpy(limit);
		final = ft_strcjoin(final, '\n');
		if (ft_strscmp(temp, final) == TRUE)
		{
			free(temp);
			break ;
		}
		index = ft_str_find_c(temp, '$');
		if (index != -1)
			temp = change_env(tree->envp_val, temp, index);
		write(tree->infile, temp, ft_strlen(temp));
		free(temp);
	}
}

static int	ft_heredoc(t_tree *tree, char *limit)
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
		return ;
	execute_heredoc(node->left, tree, 'l');
	execute_heredoc(node->right, tree, 'r');
}
	