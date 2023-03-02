/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:34:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 13:34:57 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

int	count_pipe(char **temp)
{
	int		cnt;
	int		i;

	i = -1;
	cnt = 0;
	while (temp[++i])
	{
		if (ft_strscmp(temp[i], "|") == TRUE)
			cnt++;
	}
	return (cnt + 1);
}

void	setting_pipe(t_info *info)
{
	int	i;

	info->pipe_fd = (int **)malloc(sizeof(int *) * info->pipe_cnt);
	if (info->pipe_fd == NULL)
		ft_error("malloc error //pipe.c\n");
	i = -1;
	while (++i < info->pipe_cnt)
	{
		info->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (info->pipe_fd[i] == NULL)
			ft_error("malloc error //pipe.c\n");
	}
	info->pid = (pid_t *)malloc(sizeof(pid_t) * (info->pipe_cnt + 1));
	if (info->pid == NULL)
		ft_error("malloc error //pipe.c\n");
	i = -1;
	while (++i < info->pipe_cnt)
	{
		if (pipe(info->pipe_fd[i]) == -1)
			ft_error("pipe create error //pipe.c\n");
	}
}

void	wait_pid(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->pipe_cnt)
	{
		if (i < info->pipe_cnt)
		{
			close(info->pipe_fd[i][READ]);
		}
		waitpid(info->pid[i], &info->child_status, 0);
	}
}
