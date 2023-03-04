/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:20 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 19:54:32 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	check_equal(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			if (str[i + 1] && flag == 0 && str[i + 1] == '=')
				return (0);
			flag = 1;
		}
		i++;
	}
	return (1);
}

void	find_key_value(char *str, char **key, char **value)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	*key = ft_strcpy_index(str, 0, i - 1);
	*value = ft_strcpy_index(str, i + 1, ft_strlen(str) - 1);
}

int	find_dup_key(t_env *env_list, char *key, char *value)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (tmp->key == key)
		{
			tmp->value = value;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	export_args(char **cmd, t_env **export_list, t_env **env_list)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	key = NULL;
	value = NULL;
	while (cmd[i])
	{
		if (!check_equal(cmd[i]))
			return (0);
		if (!valid_check(cmd[i]))
			return (i);
		find_key_value(cmd[i], &key, &value);
		if (!find_dup_key(*export_list, key, value))
		{
			add_env_list(*export_list, key, value);
			add_env_list(*env_list, key, value);
		}
		i++;
	}
	sort_export_list(*export_list);
	return (0);
}

int	do_export(t_tree *info)
{
	int	check_args;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "export"))
		return (1);
	if (info->cmd.cmd_arr[1])
	{
		check_args = export_args(info->cmd.cmd_arr, \
			&(info->export_list), &(info->env_list));
		if (check_args)
			return (print_error_3("export: \'", info->cmd.cmd_arr[check_args], \
			"\': not a valid identifier"));
		info->envp_val = env_to_envp(info->env_list);
	}	
	else
		print_export(info->export_list);
	return (0);
}
