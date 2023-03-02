/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:45:28 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 17:22:19 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/test.h"

static void	fork_in(t_tree *tree, int idx)
{
	if (tree->infile != 0)
	{
		close(tree->pipe_fd[idx][READ]);
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error\n");
	}
	else if (tree->next_pipe_or_file == N_FILE)
		close(tree->pipe_fd[idx][READ]);
	else
	{
		if (dup2(tree->pipe_fd[idx][READ], STDIN_FILENO) == -1)
			ft_error("dup2 error\n");
	}
}

void	fork_mid(t_tree *tree, int index)
{
	fork_in(tree, index - 1);
	close(tree->pipe_fd[index][READ]);
	if (tree->outfile != 0)
	{
		close(tree->pipe_fd[index][WRITE]);
		tree->next_pipe_or_file = N_FILE;
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error\n");
	}
	else
	{
		tree->next_pipe_or_file = PIPE;
		if (dup2(tree->pipe_fd[index][WRITE], STDOUT_FILENO) == -1)
			ft_error("dup2 error\n");
	}
	if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
		ft_error("cmd option error child\n");
}
