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

int	check_export(char *str)
{
	if (!ft_strncmp(str, "export", 6))
		return (1);
	return (0);
}

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
	*key = ft_substr(str, 0, i);
	*value = ft_substr(str, i + 1, ft_strlen(str));
}

void	print_export(t_env_list *export_list)
{
	t_env_list	*tmp;

	tmp = export_list;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	do_export(char **str, t_env_list *export_list)
{
	char		*key;
	char		*value;
	size_t		i;

	if (!check_export(str[0]))
		return ;
	key = NULL;
	value = NULL;
	if (str[1])
	{
		i = 1;
		while (str[i])
		{
			if (!check_equal(str[i]))
				return ;
			find_key_value(str[i], &key, &value);
			add_env_list(export_list, key, value);
			i++;
		}
		sort_export_list(export_list);
	}
	print_export(export_list);
}
