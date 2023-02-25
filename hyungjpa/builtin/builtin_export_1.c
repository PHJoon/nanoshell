/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:20 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/22 14:52:22 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	check_equal(char *str)
{
	size_t	i;
	int		flag;

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
	size_t	i;

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

int	find_dup_key(t_env_list *env_list, char *key, char *value)
{
	t_env_list	*tmp;

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

void	export_args(char **str, t_env_list **export_list, t_env_list **env_list)
{
	size_t	i;
	char	*key;
	char	*value;

	i = 1;
	key = NULL;
	value = NULL;
	while (str[i])
	{
		if (!check_equal(str[i]))
			return ;
		find_key_value(str[i], &key, &value);
		if (!find_dup_key(*export_list, key, value))
		{
			add_env_list(*export_list, key, value);
			add_env_list(*env_list, key, value);
		}
		i++;
	}
	sort_export_list(*export_list);
}

void	do_export(char **str, t_env_list **export_list, t_env_list **env_list)
{
	if (!ft_strscmp(str[0], "export"))
		return ;
	if (str[1])
		export_args(str, export_list, env_list);
	else
		print_export(*export_list);
}
