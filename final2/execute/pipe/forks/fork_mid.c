/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:45:28 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 21:16:32 by chanson          ###   ########.fr       */
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
			ft_error("dup2 error4\n");
	}
	else if (tree->next_pipe_or_file == N_FILE)
		close(tree->pipe_fd[idx][READ]);
	else
	{
		if (dup2(tree->pipe_fd[idx][READ], STDIN_FILENO) == -1)
			ft_error("dup2 error5\n");
	}
	close(tree->pipe_fd[idx + 1][READ]);
}

static void	close_pipe_not_use(t_tree *tree, int index)
{
	int	i;

	i = 0;
	while (i < tree->pipe_cnt)
	{
		if (i == index || i == index -1)
			i++;
		else
		{
			close(tree->pipe_fd[i][READ]);
			close(tree->pipe_fd[i][WRITE]);
			i++;
		}
	}
}

static void	infile_outfile_check(t_tree *tree, int index)
{
	if (tree->outfile != 0)
	{
		close(tree->pipe_fd[index][WRITE]);
		tree->next_pipe_or_file = N_FILE;
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error6\n");
	}
	else
	{
		tree->next_pipe_or_file = PIPE;
		if (dup2(tree->pipe_fd[index][WRITE], STDOUT_FILENO) == -1)
			ft_error("dup2 error7\n");
	}
}

void	fork_mid(t_tree *tree, int index)
{
	int	builtin_num;

	close_pipe_not_use(tree, index);
	fork_in(tree, index - 1);
	infile_outfile_check(tree, index);
	builtin_num = builtin_pipe(tree);
	if (builtin_num != 1)
		exit(builtin_num);
	if (builtin_num == 1)
	{
		if (tree->cmd.cmd_head == NULL)
			print_error_2("cmd not valid: ", tree->cmd.cmd_arr[0]);
		if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
			ft_error("cmd option error child\n");
	}
}
