/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_remove_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:30:46 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 15:30:57 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	check_remove_quote(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\'' || str[i] == '"')
	{
		i++;
		if (str[i] == '<' || str[i] == '>' || str[i] == '|' || \
		str[i] == '&' || str[i] == '(')
			return (0);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (-1);
		i++;
	}
	if (str[0] == '\'')
		return (1);
	else if (str[0] == '"')
		return (2);
	return (0);
}

char	**remove_quote(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (check_remove_quote(temp[i]) == 1)
			temp[i] = ft_strtrim(temp[i], '\'');
		else if (check_remove_quote(temp[i]) == 2)
			temp[i] = ft_strtrim(temp[i], '"');
		i++;
	}
	return (temp);
}
