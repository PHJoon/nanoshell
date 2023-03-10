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
		if (ft_strscmp(tmp->key, key))
		{
			free(tmp->key);
			tmp->key = key;
			free(tmp->value);
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
		find_key_value(cmd[i], &key, &value);
		printf("%s %s\n", key, value);
		if (!valid_check(&key))
			return (i);
		if (!find_dup_key(*export_list, key, value))
		{
			add_env_list(*export_list, ft_strcpy(key), ft_strcpy(value));
			add_env_list(*env_list, ft_strcpy(key), ft_strcpy(value));
			free(key);
			free(value);
		}
		i++;
	}
	sort_export_list(*export_list);
	return (0);
}

int	do_export(t_tree *info)
{
	int		check_args;
	char	**temp;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "export"))
		return (1);
	temp = export_split(info->origin);
	if (temp[1])
	{
		check_args = export_args(temp, &(info->export_list), &(info->env_list));
		if (check_args)
		{
			print_error_3("export: \'", temp[check_args], \
			"\': not a valid identifier");
			ft_free_str(temp);
			return (2);
		}
		ft_free_str(info->envp_val);
		info->envp_val = env_to_envp(info->env_list);
	}	
	else
		print_export(info->export_list);
	ft_free_str(temp);
	return (0);
}
