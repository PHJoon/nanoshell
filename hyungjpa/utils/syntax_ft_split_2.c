/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_ft_split_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:08:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

int	ft_split_pipe(char ***temp, char *str, int idx)
{
	char	*buff;
	int		cnt;

	buff = NULL;
	cnt = 0;
	buff = ft_strcjoin(buff, str[idx++]);
	if (str[idx] == '|')
	{
		buff = ft_strcjoin(buff, str[idx]);
		cnt++;
	}
	*temp = ft_strsjoin(*temp, buff);
	return (cnt);
}

int	ft_split_redirection(char ***temp, char *str, int idx)
{
	char	*buff;

	buff = NULL;
	buff = ft_strcjoin(buff, str[idx]);
	if (str[idx] == '<' && str[idx + 1] == '<')
	{
		buff = ft_strcjoin(buff, str[idx + 1]);
		*temp = ft_strsjoin(*temp, buff);
		return (1);
	}
	else if (str[idx] == '>' && str[idx + 1] == '>')
	{
		buff = ft_strcjoin(buff, str[idx + 1]);
		*temp = ft_strsjoin(*temp, buff);
		return (1);
	}
	*temp = ft_strsjoin(*temp, buff);
	return (0);
}

int	_ft_split_quote(char *str, int idx, char **buff)
{
	int	cnt;

	*buff = ft_strcjoin(*buff, str[idx++]);
	cnt = 0;
	while (str[idx])
	{
		*buff = ft_strcjoin(*buff, str[idx]);
		if (str[idx] == '\"')
			break ;
		idx++;
		cnt++;
	}
	return (cnt);
}

int	ft_split_quote(char ***temp, char *str, int idx)
{
	char	*buff;
	int		cnt;

	buff = NULL;
	cnt = 0;
	if (str[idx] == '\'')
	{
		buff = ft_strcjoin(buff, str[idx++]);
		while (str[idx])
		{
			buff = ft_strcjoin(buff, str[idx]);
			if (str[idx] == '\'')
				break ;
			cnt++;
			idx++;
		}
		*temp = ft_strsjoin(*temp, buff);
		return (cnt + 1);
	}
	cnt = _ft_split_quote(str, idx, &buff);
	*temp = ft_strsjoin(*temp, buff);
	return (cnt + 1);
}
