/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:21:39 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 20:04:29 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	relink_env_list(t_env *tmp)
{
	if (tmp->prev)
	{
		if (tmp->next)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		else
			tmp->prev->next = NULL;
	}
	else
	{
		if (tmp->next)
			tmp->next->prev = NULL;
	}
}

int	list_unset(char **cmd, t_env **env_list)
{
	t_env	*tmp;
	int		i;

	if (!ft_strscmp(cmd[0], "unset"))
		return (-1);
	tmp = *env_list;
	while (tmp)
	{
		i = 1;
		while (cmd[i])
		{
			if (!valid_check(cmd[i]))
				return (i);
			if (ft_strscmp(tmp->key, cmd[i]))
			{
				relink_env_list(tmp);
				free(tmp->key);
				free(tmp->value);
				free(tmp);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	do_unset(t_tree *info)
{
	int	res1;
	int	res2;

	res1 = list_unset(info->cmd.cmd_arr, &(info->env_list));
	res2 = list_unset(info->cmd.cmd_arr, &(info->export_list));
	info->envp_val = env_to_envp(info->env_list);
	if (res1 == -1)
		return (1);
	else if (res1 > 0)
		return (print_error_3("export: \'", info->cmd.cmd_arr[res1], \
			"\': not a valid identifier"));
	return (0);
}
