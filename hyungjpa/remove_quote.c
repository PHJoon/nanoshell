/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:40:16 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/23 17:40:18 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

int	check_remove_quote(char *str)
{
	size_t	i;

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
	size_t	i;

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
