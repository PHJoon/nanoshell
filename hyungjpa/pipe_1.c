/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:28:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 17:28:56 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

void	print_error_exit_1(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(2);
}

void	print_error_exit_2(char *str1, char *str2)
{
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
	exit(2);
}

t_info	*check_pipe_fd(t_info *info, int pipe_idx)
{
	if (pipe_idx == info->pipe_cnt - 1)
	{
		if (pipe_idx != 0)
		{
			close(info->pipe_fd[pipe_idx - 1][WRITE]);
			if (info->infile == 0)
				info->infile = info->pipe_fd[pipe_idx - 1][READ];
			else
				close(info->pipe_fd[pipe_idx - 1][READ]);
		}	
		close(info->pipe_fd[pipe_idx][READ]);
		close(info->pipe_fd[pipe_idx][WRITE]);
	}
	else if (pipe_idx != info->pipe_cnt - 1)
	{
		if (pipe_idx != 0)
		{
			close(info->pipe_fd[pipe_idx - 1][WRITE]);
			if (info->infile == 0)
				info->infile = info->pipe_fd[pipe_idx - 1][READ];
			else
				close(info->pipe_fd[pipe_idx - 1][READ]);
		}	
		close(info->pipe_fd[pipe_idx][READ]);
		if (info->outfile == 1)
			info->outfile = info->pipe_fd[pipe_idx][WRITE];
		else
			close(info->pipe_fd[pipe_idx][WRITE]);
	}
	return (info);
}

void	do_fork(t_info *info, int pipe_idx)
{
	int	builtin_check;

	info->pid[pipe_idx] = fork();
	if (info->pid[pipe_idx] < 0)
		print_error_exit_1("fork error");
	if (info->pid[pipe_idx] == 0)
	{
		do_signal_handle(CHILD);
		info = check_pipe_fd(info, pipe_idx);
		if (dup2(info->infile, STDIN_FILENO) == -1)
			print_error_exit_1("dup2 error child fork");
		if (dup2(info->outfile, STDOUT_FILENO) == -1)
			print_error_exit_1("dup2 error child fork");
		builtin_check = builtin(info);
		if (builtin_check == 1)
		{
			get_cmd_path(info);
			if (execve(info->cmd[0], info->cmd, info->new_envp) == -1)
				print_error_exit_1("execve error child fork");
		}
		else
			exit(builtin_check);
	}
	else
		close(info->pipe_fd[pipe_idx][WRITE]);
}

int	idx_move_next(char **temp, int idx)
{
	while (!ft_strscmp(temp[idx], "|") && temp[idx])
		idx++;
	if (!temp[idx])
		return (idx);
	return (idx + 1);
}

void	pipex(t_info *info)
{
	int	i;
	int	pipe_idx;

	i = 0;
	pipe_idx = 0;
	while (info->temp[i])
	{
		info->infile = get_ird(&info->temp[i]);
		info->outfile = get_ord(&info->temp[i]);
		info->cmd = cmd_get(&info->temp[i]);
		i = idx_move_next(info->temp, i);
		do_fork(info, pipe_idx);
		on_off_catch_signals(OFF);
		pipe_idx++;
	}
	wait_pid(info);
}
