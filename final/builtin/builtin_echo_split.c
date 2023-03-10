/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:05:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/07 19:05:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static char	*split_space(char *str, int *i, int *flag)
{
	char	*tmp;

	tmp = NULL;
	*flag = 1;
	tmp = ft_strcjoin(tmp, str[*i]);
	(*i)++;
	return (tmp);
}

static char	*split_char(char *str, int *i, int *flag)
{
	char	*tmp;

	tmp = NULL;
	while (str[*i] && str[*i] != '"' && str[*i] != '\'' && str[*i] != ' ')
	{
		tmp = ft_strcjoin(tmp, str[*i]);
		(*i)++;
	}
	*flag = 0;
	return (tmp);
}

static char	*split_quote(char *str, int *i, int *flag)
{
	char	*tmp;

	tmp = NULL;
	if (str[*i] == '"')
	{
		tmp = ft_strcjoin(tmp, str[(*i)++]);
		while (str[*i] && str[*i] != '"')
		{
			tmp = ft_strcjoin(tmp, str[*i]);
			(*i)++;
		}
		tmp = ft_strcjoin(tmp, str[(*i)++]);
	}
	else if (str[*i] == '\'')
	{
		tmp = ft_strcjoin(tmp, str[(*i)++]);
		while (str[*i] && str[*i] != '\'')
		{
			tmp = ft_strcjoin(tmp, str[*i]);
			(*i)++;
		}
		tmp = ft_strcjoin(tmp, str[(*i)++]);
	}
	*flag = 0;
	return (tmp);
}

char	**echo_split(char *str)
{
	int		i;
	char	**new_temp;
	char	*tmp;
	int		flag;

	i = 0;
	new_temp = NULL;
	tmp = NULL;
	flag = 1;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			if (flag == 0)
				tmp = split_space(str, &i, &flag);
			else
			{
				i++;
				continue ;
			}
		}
		else if (str[i] != '"' && str[i] != '\'')
			tmp = split_char(str, &i, &flag);
		else if (str[i] == '"' || str[i] == '\'')
			tmp = split_quote(str, &i, &flag);
		new_temp = ft_strsjoin(new_temp, ft_strcpy(tmp));
		free(tmp);
		tmp = NULL;
	}
	return (new_temp);
}
