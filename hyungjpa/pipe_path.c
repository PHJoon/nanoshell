/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:50:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 14:50:14 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

void	get_path(t_info *info)
{
	char	*path_val;

	path_val = find_path(info);
	info->path = ft_split_path(path_val, ':');
}

void	get_cmd_path(t_info *info)
{
	int		i;
	char	*path_tmp;
	char	*acc_tmp;

	i = 0;
	if (!access(info->cmd[0], X_OK))
		return ;
	while (info->path[i])
	{
		path_tmp = ft_strjoin(info->path[i], "/");
		acc_tmp = ft_strjoin(path_tmp, info->cmd[0]);
		free(path_tmp);
		if (!access(acc_tmp, X_OK))
		{
			free(info->cmd[0]);
			info->cmd[0] = acc_tmp;
			return ;
		}
		free(acc_tmp);
		i++;
	}
	write(2, "command not found!\n", 19);
}
