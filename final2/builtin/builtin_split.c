/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:53:35 by chanson           #+#    #+#             */
/*   Updated: 2023/03/09 20:08:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void	cut_space_first(char ***result)
{
	int		i;
	int		j;
	char	*temp;

	if (*result == NULL)
		return ;
	i = -1;
	while ((*result)[++i] != NULL)
	{
		j = 0;
		while ((*result)[i][j] == ' ')
			j++;
		if (j > 0)
		{
			temp = ft_strcpy((*result)[i]);
			free((*result)[i]);
			(*result)[i] = NULL;
			(*result)[i] = ft_strcpy_index(temp, j, ft_strlen(temp) - 1);
			free(temp);
		}
	}
}

char	**builtin_split(char *str)
{
	int		i;
	int		flag;
	char	**result;
	char	*temp;

	result = NULL;
	flag = 0;
	temp = NULL;
	i = 0;
	while (1)
	{
		if (flag == 0 && str[i] == '|')
		{
			result = ft_strsjoin(result, ft_strcpy(temp));
			free(temp);
			temp = NULL;
		}
		else if (str[i] == '\0')
		{
			if (temp != NULL)
			{
				result = ft_strsjoin(result, ft_strcpy(temp));
				free(temp);
				temp = NULL;
			}
			break ;
		}
		else if (flag == 0 && str[i] == '\"')
		{
			flag = 1;
			temp = ft_strcjoin(temp, str[i]);
		}
		else if (flag == 0 && str[i] == '\'')
		{
			flag = 2;
			temp = ft_strcjoin(temp, str[i]);
		}
		else if (flag == 1 && str[i] == '\"')
		{
			flag = 0;
			temp = ft_strcjoin(temp, str[i]);
		}
		else if (flag == 2 && str[i] == '\'')
		{
			flag = 0;
			temp = ft_strcjoin(temp, str[i]);
		}
		else
			temp = ft_strcjoin(temp, str[i]);
		i++;
	}
	cut_space_first(&result);
	return (result);
}
