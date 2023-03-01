/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:46:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

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

void	print_env_var(char *str, t_env *env_list)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			j = 0;
			while (str[i + j] && str[i + j] != '$' && \
			str[i + j] != '\'' && str[i + j] != '"')
				j++;
			tmp = ft_strcpy_index(str, i, i + j - 1);
			find_value_print(env_list, tmp);
			free(tmp);
			i += j;
		}
		else
		{
			printf("%c", str[i]);
			i++;
		}
	}
}

void	check_env_var(char *str, t_env *env_list)
{
	char	*tmp;

	if (check_remove_quote(str) == -1)
	{
		if (str[0] == '\'')
		{
			tmp = ft_strtrim(str, '\'');
			printf("%s", tmp);
			free(tmp);
		}
		else if (str[0] == '"')
		{
			tmp = ft_strtrim(str, '"');
			print_env_var(tmp, env_list);
			free(tmp);
		}
		else
			print_env_var(str, env_list);
	}
	else
		printf("%s", str);
}

int	do_echo(char **temp, t_env *env_list)
{
	int	flag;
	int	i;

	flag = 1;
	i = 1;
	if (!ft_strscmp(temp[0], "echo"))
		return (1);
	if (echo_option(temp[i]) == -1)
		return (0);
	while (echo_option(temp[i]) == 1)
	{
		i++;
		flag = 0;
	}
	while (temp[i])
	{
		check_env_var(temp[i], env_list);
		i++;
		if (i != str_size(temp))
			printf(" ");
	}
	if (flag)
		printf("\n");
	return (0);
}
