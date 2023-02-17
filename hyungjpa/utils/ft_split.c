/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:02:12 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 13:40:37 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	dispaly_str(char **str);

static int	ft_split_pipe(char ***temp, char *str, int idx)
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

static int	ft_split_redirection(char ***temp, char *str, int idx)
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

static int	_ft_split_quote(char *str, int idx, char **buff)
{
	int		cnt;

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

static int	ft_split_quote(char ***temp, char *str, int idx)
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

char	**ft_split(char *s)
{
	char	**temp;
	char	*buff;
	int		i;

	i = 0;
	buff = NULL;
	temp = NULL;
	while (s[i])
	{
		if (s[i] != '|' && s[i] != '\'' && s[i] != '\"' && s[i] != ' ' && \
			s[i] != '&' && s[i] != '>' && s[i] != '<' && s[i] != '(')
			buff = ft_strcjoin(buff, s[i]);
		else
		{
			if (buff != NULL)
				temp = ft_strsjoin(temp, buff);
			buff = NULL;
			if (s[i] == '|')
				i += ft_split_pipe(&temp, s, i);
			else if (s[i] == '\'' || s[i] == '\"')
				i += ft_split_quote(&temp, s, i);
			else if (s[i] == '>' || s[i] == '<')
				i += ft_split_redirection(&temp, s, i);
			else if (s[i] == '&')
				i += ft_split_and(&temp, s, i);
			else if (s[i] == '(')
				i += ft_split_par(&temp, s, i);
		}
		if (s[i] != '\0')
			i++;
	}
	if (buff != NULL)
		temp = ft_strsjoin(temp, buff);
	return (temp);
}

void dispaly_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("display: %s\n", str[i]);
		i++;
	}
}