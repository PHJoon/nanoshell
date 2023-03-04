/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:46:13 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 16:18:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	close_fd(int *cnt, int fd)
{
	if (*cnt != 0)
		close(fd);
	(*cnt)++;
}

int	get_ird(char **temp)
{
	int	i;
	int	ird_fd;
	int	cnt;

	i = -1;
	ird_fd = 0;
	cnt = 0;
	while (!ft_strscmp(temp[++i], "|") && temp[i])
	{
		if (ft_strscmp(temp[i], "<"))
		{
			close_fd(&cnt, ird_fd);
			ird_fd = open(temp[i + 1], O_RDONLY);
			if (ird_fd == -1)
			{
				print_error_2("no such file or directory: ", temp[i + 1]);
				exit(-1);
			}
			i++;
		}
	}
	return (ird_fd);
}

int	get_ord(char **temp)
{
	int	i;
	int	ord_fd;
	int	cnt;

	i = -1;
	ord_fd = 0;
	cnt = 0;
	while (!ft_strscmp(temp[++i], "|") && temp[i])
	{
		if (ft_strscmp(temp[i], ">"))
		{
			close_fd(&cnt, ord_fd);
			ord_fd = open(temp[++i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (ord_fd == -1)
				ft_error("open_error\n");
		}
		else if (ft_strscmp(temp[i], ">>"))
		{
			close_fd(&cnt, ord_fd);
			ord_fd = open(temp[++i], O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (ord_fd == -1)
				ft_error("open_error\n");
		}
	}
	return (ord_fd);
}

static char	**_cmd_get(char **temp, char **cmd)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (!ft_strscmp(temp[++i], "|") && temp[i])
	{
		if (ft_strscmp(temp[i], "<") || ft_strscmp(temp[i], ">") \
		|| ft_strscmp(temp[i], ">>"))
			i++;
		else
		{
			cmd[size] = ft_strcpy(temp[i]);
			size++;
		}
	}
	cmd[size] = NULL;
	return (cmd);
}

char	**cmd_get(char **temp)
{
	int		i;
	int		size;
	char	**cmd;

	i = -1;
	size = 0;
	while (!ft_strscmp(temp[++i], "|") && temp[i])
	{
		if (ft_strscmp(temp[i], "<") || ft_strscmp(temp[i], ">") \
		|| ft_strscmp(temp[i], ">>"))
			i++;
		else
			size++;
	}
	cmd = (char **)malloc(sizeof(char *) * (size + 1));
	if (!cmd)
		return (cmd);
	cmd = _cmd_get(temp, cmd);
	return (cmd);
}
