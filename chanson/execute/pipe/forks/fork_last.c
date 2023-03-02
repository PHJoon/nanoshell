/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:57:16 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 21:17:29 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/test.h"

static void	fork_in(t_tree *tree, int idx)
{
	close(tree->pipe_fd[idx][WRITE]);
	if (tree->infile != 0)
	{
		close(tree->pipe_fd[idx][READ]);
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error8\n");
	}
	else if (tree->next_pipe_or_file == N_FILE)
		close(tree->pipe_fd[idx][READ]);
	else
	{
		if (dup2(tree->pipe_fd[idx][READ], STDIN_FILENO) == -1)
			ft_error("dup2 error9\n");
	}
}

void	fork_last(t_tree *tree)
{
	int	builtin_num;

	fork_in(tree, tree->pipe_cnt - 1);
	if (tree->outfile != 0)
	{
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error10\n");
	}
	builtin_num = builtin(tree);
	// builtin_num = 1;
	if (builtin_num == 1)
	{
		if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
			ft_error("cmd option error child\n");
	}
}
