/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:43:24 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 15:26:11 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/test.h"

void	fork_first(t_tree *tree)
{
	close(tree->pipe_fd[0][READ]);
	if (tree->infile != 0)
	{
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error\n");
	}
	if (tree->outfile != 0)
	{
		tree->next_pipe_or_file = N_FILE;
		close(tree->pipe_fd[0][WRITE]);
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error\n");
	}
	else
	{
		tree->next_pipe_or_file = PIPE;
		if (dup2(tree->pipe_fd[0][WRITE], STDOUT_FILENO) == -1)
			ft_error("dup2 error\n");
	}
	if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
		ft_error("cmd option error child\n");
}
