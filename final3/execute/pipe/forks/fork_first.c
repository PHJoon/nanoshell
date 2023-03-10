/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:43:24 by chanson           #+#    #+#             */
/*   Updated: 2023/03/10 14:43:29 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/test.h"

static void	_fork_in(t_tree *tree)
{
	if (tree->infile != 0)
	{
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error1\n");
	}
	if (tree->outfile != 0)
	{
		tree->next_pipe_or_file = N_FILE;
		close(tree->pipe_fd[0][WRITE]);
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error2\n");
	}
	else
	{
		tree->next_pipe_or_file = PIPE;
		if (dup2(tree->pipe_fd[0][WRITE], STDOUT_FILENO) == -1)
			ft_error("dup2 error3\n");
	}
}

void	fork_first(t_tree *tree)
{
	int	builtin_num;
	int	i;

	i = 1;
	while (i < tree->pipe_cnt)
	{
		close(tree->pipe_fd[i][READ]);
		close(tree->pipe_fd[i][WRITE]);
		i++;
	}
	close(tree->pipe_fd[0][READ]);
	_fork_in(tree);
	builtin_num = builtin_pipe(tree);
	if (builtin_num != 1)
		exit(builtin_num);
	if (builtin_num == 1)
	{
		if (tree->cmd.cmd_head == NULL)
			prt_err_2(tree->cmd.cmd_arr[0], ": cmd not found");
		if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
			ft_error("cmd option error child\n");
	}
}
