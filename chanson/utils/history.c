/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:12:07 by chanson           #+#    #+#             */
/*   Updated: 2023/02/27 20:57:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

static void	clear_terminal(t_cusor *cusor)
{
	while (cusor->col > cusor->start)
	{
		--(cusor->col);
		tputs(tgoto(cusor->cm, cusor->col, cusor->row), \
			1, putchar_tc);
		tputs(cusor->ce, 1, putchar_tc);
	}
}

static char	*history_up(t_cusor *cusor, char **history)
{
	char	*str;
	int		idx;

	clear_terminal(cusor);
	str = NULL;
	if (history[cusor->h_index] == NULL)
		return (NULL);
	str = ft_strcpy(history[cusor->h_index]);
	idx = -1;
	while (str[++idx])
	{
		write(0, &str[idx], 1);
		++(cusor->col);
		++(cusor->end);
	}
	return (str);
}

static char	*history_down(t_cusor *cusor, char **history)
{
	char	*str;
	int		idx;

	clear_terminal(cusor);
	str = NULL;
	if (history[cusor->h_index] == NULL)
		return (NULL);
	str = ft_strcpy(history[cusor->h_index]);
	idx = -1;
	while (str[++idx])
	{
		write(0, &str[idx], 1);
		++(cusor->col);
		++(cusor->end);
	}
	return (str);
}

char	*history_up_down(t_cusor *cusor, char *str, char **history, char c)
{
	static char	*dis;
	char		*answer;
	int			end;

	end = 0;
	answer = NULL;
	while (history[end])
		end++;
	if (dis == NULL || ft_strscmp(dis, str) == FALSE)
	{
		free(dis);
		dis = ft_strcpy(str);
		cusor->h_index = end;
	}
	if (c == 'u')
	{
		if (cusor->h_index > 0)
			cusor->h_index--;
		answer = history_up(cusor, history);
		return (answer);
	}
	if (cusor->h_index < end)
		cusor->h_index++;
	answer = history_down(cusor, history);
	return (answer);
}
