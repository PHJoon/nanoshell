/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:46:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/11 21:47:19 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	echo_option(char *str)
{
	size_t	i;

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

void	find_value_print(t_env_list *env_list, char *key)
{
	t_env_list	*tmp;

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

void	print_env_var(char *str, t_env_list *env_list)
{
	size_t	i;
	size_t	j;
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

void	check_env_var(char *str, t_env_list *env_list)
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

void	do_echo(char **str, t_env_list *env_list)
{
	int		flag;
	size_t	i;

	flag = 1;
	i = 1;
	if (!ft_strscmp(str[0], "echo"))
		return ;
	while (echo_option(str[i]) == 1)
	{
		i++;
		flag = 0;
	}
	if (echo_option(str[i]) == -1)
		return ;
	while (str[i])
	{
		check_env_var(str[i], env_list);
		i++;
		if (i != str_size(str))
			printf(" ");
	}
	if (flag)
		printf("\n");
}
