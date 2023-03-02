/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:36 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 15:27:58 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	cd_home(t_env *env_list)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strscmp(tmp->key, "HOME"))
		{
			chdir(tmp->value);
			return ;
		}
		tmp = tmp->next;
	}
}

int	check_dir(char *cwd_buf)
{
	DIR	*dir_info;

	dir_info = opendir(cwd_buf);
	if (dir_info)
	{
		closedir(dir_info);
		return (1);
	}
	closedir(dir_info);
	free(cwd_buf);
	return (0);
}
