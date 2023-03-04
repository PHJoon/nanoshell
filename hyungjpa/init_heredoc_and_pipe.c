/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc_and_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:29:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/04 23:30:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

static void	start_cmd(t_tree *tree, char **temp)
{
	if (tree->pipe_cnt > 0)
		execute_pipe(temp, tree);
	else
		execute_no_pipe(temp, tree);
}

static t_tree	*init_heredoc(t_tree *tree, char ***temp)
{
	cnt_heredoc(tree->top, tree);
	tree->here_documets = (char **)malloc(sizeof(char *) * \
		(tree->here_doc_cnt + 1));
	if (!tree->here_documets)
		ft_error("malloc error\n");
	tree->here_documets[tree->here_doc_cnt] = NULL;
	execute_heredoc(tree->top, tree, 's');
	ft_free_str(*temp);
	*temp = NULL;
	heredoc_sum(tree->top, temp);
	return (tree);
}

void	_init_heredoc_and_pipe(t_tree *tree, char ***temp)
{
	tree = init_heredoc(tree, temp);
	tree->pipe_cnt = count_pipe(*temp);
	start_cmd(tree, *temp);
	ft_free_tree(tree);
	ft_free_str(*temp);
	*temp = NULL;
}
