/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:02:12 by chanson           #+#    #+#             */
/*   Updated: 2023/02/13 17:40:52 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void dispaly_str(char **str);

static void	ft_split_pipe(char ***temp, char *str, int idx)
{
	char	*buff;

	buff = NULL;
	buff = ft_strcjoin(buff, str[idx]);
	*temp = ft_strsjoin(*temp, buff);
}

static int	ft_split_redirection(char ***temp, char *str, int idx)
{
	char	*buff;
	int		cnt;

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

static int	ft_split_quote(char ***temp, char *str, int idx)
{
	char	*buff;
	int		cnt;

	buff = NULL;
	cnt = 0;
	if (str[idx] == '\'')
	{
		while (str[++idx] != '\'')
		{
			buff = ft_strcjoin(buff, str[idx]);
			cnt++;
		}
		*temp = ft_strsjoin(*temp, buff);
		return (cnt + 1);
	}
	while (str[++idx] != '\"')
	{
		buff = ft_strcjoin(buff, str[idx]);
		cnt++;
	}
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
	printf("start: %s\n\n", s);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '|' && s[i] != '\'' && \
			s[i] != '\"' && s[i] != '>' && s[i] != '<')
			buff = ft_strcjoin(buff, s[i]);
		else
		{
			if (buff != NULL)
				temp = ft_strsjoin(temp, buff);
			buff = NULL;
			if (s[i] == '|')
				ft_split_pipe(&temp, s, i);
			else if (s[i] == '\'' || s[i] == '\"')
				i += ft_split_quote(&temp, s, i);
			else if (s[i] == '>' || s[i] == '<')
				i += ft_split_redirection(&temp, s, i);
		}
		if (s[i] != '\0')
			i++;
	}
	if (buff != NULL)
		temp = ft_strsjoin(temp, buff);
	dispaly_str(temp);
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