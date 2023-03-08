/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:46:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/05 19:33:31 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	echo_option(char *str)
{
	int	i;

	i = 1;
	if (str == NULL)
	{
		printf("\n");
		return (-1);
	}
	if (str[0] == '-')
	{
		while (str[i] == 'n')
			i++;
		if (i != ft_strlen(str) || i == 1)
			return (0);
		return (1);
	}
	return (0);
}

void	find_value_print(t_env *env_list, char *key)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strscmp(tmp->key, key))
		{
			printf("%s", tmp->value);
			return ;
		}
		tmp = tmp->next;
	}
}

int	print_env_value(char *s, int start, t_env *env_list)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[start + i] && s[start + i] != '"' && s[start + i] != '\'' \
	&& s[start + i] != '$' && s[start + i] != ' ')
		i++;
	tmp = ft_strcpy_index(s, start, start + i - 1);
	find_value_print(env_list, tmp);
	free(tmp);
	return (i + 1);
}

void	ft_echo(char **temp, int i, int flag, t_env *env_list)
{
	int	cnt;

	cnt = 0;
	while (temp[i])
	{
		if (!(cnt == 0 && ft_strscmp(temp[i], " ")))
			remove_quote_and_print(temp[i], env_list);
		cnt++;
		i++;
	}
	if (flag)
		printf("\n");
}

int	do_echo(t_tree *info)
{
	int		flag;
	int		i;
	char	**temp;

	flag = 1;
	i = 1;
	temp = echo_split(info->origin);
	if (!ft_strscmp(temp[0], "echo"))
	{
		ft_free_str(temp);
		return (1);
	}
	if (echo_option(temp[i]) == -1)
	{
		ft_free_str(temp);
		return (0);
	}
	while (echo_option(temp[i]) == 1)
	{
		i++;
		flag = 0;
	}
	ft_echo(temp, i, flag, info->env_list);
	ft_free_str(temp);
	return (0);
}
