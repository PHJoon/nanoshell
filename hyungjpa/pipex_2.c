/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:50:28 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/23 15:50:33 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

size_t	count_pipe(char **temp)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (temp[i])
	{
		if (!ft_strncmp(temp[i], "|", 2))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**get_redirection(char **temp, size_t i)
{
	size_t	redir_cnt;
	size_t	j;
	char	**redir_temp;

	redir_cnt = 0;
	j = 0;
	while (temp[i + j] != "|")
	{
		if (!ft_strncmp(temp[i + j], "<", 2) || \
		!ft_strncmp(temp[i + j], ">", 2) || \
		!ft_strncmp(temp[i + j], ">>", 3))
			redir_cnt += 2;
		j++;
	}
	redir_temp = (char **)malloc(sizeof(char *) * (redir_cnt + 1));
	if (!redir_temp)
		return (NULL);
	j = 0;
	while (redir_cnt)
	{
		redir_temp[j] = ft_strdup(temp[i + j]);
		j++;
		redir_cnt--;
	}
	return (redir_temp);
}

char	*get_cmd(char **temp, size_t *i)
{
	size_t	j;
	char	*tmp;
	char	*cmd_temp;

	j = 0;
	cmd_temp = NULL;
	while (temp[*i + j] != "|")
	{
		if (!ft_strncmp(temp[*i + j], "<", 2) || \
		!ft_strncmp(temp[*i + j], ">", 2) || \
		!ft_strncmp(temp[*i + j], ">>", 3))
			j += 2;
		else
		{
			tmp = ft_strjoin(cmd_temp, temp[*i + j]);
			free(cmd_temp);
			cmd_temp = tmp;
			j++;
		}
	}
	*i += j + 1;
	return (cmd_temp);
}



int	do_pipe(char **temp, char **envp)
{
	size_t	pipe_cnt;
	t_pipex	pipex;
	size_t	i;
	char	**redir_temp;
	char	*cmd_temp;

	pipe_cnt = count_pipe(temp) + 1;
	i = 0;
	if (!pipe_cnt)
	{
		do_fork(pipex, envp, 0);
	}
	else
	{
		while (temp[i])
		{
			redir_temp = get_redirection(temp, i);
			cmd_temp = get_cmd(temp, &i);
			do_fork()




		}
	}
}

void	do_fork(t_pipex *pipex, char **envp, int num)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		put_perror("fork error!", pipex);
	else if (pid == 0)
	{
		if (num == 0)
		{
			close(pipex->pipe_a[0]);
			if (dup2(pipex->infile, STDIN_FILENO) == -1)
				put_perror("dup2 error!", pipex);
			if (dup2(pipex->pipe_a[1], STDOUT_FILENO) == -1)
				put_perror("dup2 error!", pipex);
			if (execve(pipex->cmd1[0], pipex->cmd1, envp) == -1)
				put_perror("execve error!", pipex);
		}
		else
		{
			close(pipex->pipe_b[0]);
			if (dup2(pipex->infile, STDIN_FILENO) == -1)
				put_perror("dup2 error!", pipex);
			if (dup2(pipex->pipe_b[1], STDOUT_FILENO) == -1)
				put_perror("dup2 error!", pipex);
			if (execve(pipex->cmd1[0], pipex->cmd1, envp) == -1)
				put_perror("execve error!", pipex);

		}
	}
	else
		return ;
}
