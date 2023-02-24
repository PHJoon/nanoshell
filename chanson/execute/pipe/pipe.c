/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:06:18 by chanson           #+#    #+#             */
/*   Updated: 2023/02/23 19:44:34 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.h"

static int	_count_pipe_parentheses(char *str)
{
	char	**str_par;
	int		i;
	int		cnt;

	str_par = ft_split(str);
	cnt = 0;
	i = -1;
	while (str_par[++i])
	{
		if (ft_strscmp(str_par[i], "|") == TRUE)
			cnt++;
	}
	ft_free_str(str_par);
	return (cnt);
}

int	count_pipe(char **temp)
{
	int		cnt;
	int		i;
	char	*str;

	i = -1;
	cnt = 0;
	while (temp[++i])
	{
		if (ft_strscmp(temp[i], "|") == TRUE)
			cnt++;
		else if (temp[i][0] == '(')
		{
			str = ft_strtrim_couple_check(temp[i], '(', ')');
			cnt += _count_pipe_parentheses(str);
			free(str);
		}
	}
	return (cnt);
}
