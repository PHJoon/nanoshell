/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:46 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 13:31:56 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	ft_split_and(char ***temp, char *str, int idx)
{
	char	*buff;
	int		cnt;

	cnt = 0;
	buff = NULL;
	buff = ft_strcjoin(buff, str[idx++]);
	if (str[idx] == '&')
	{
		buff = ft_strcjoin(buff, str[idx]);
		cnt++;
	}
	*temp = ft_strsjoin(*temp, buff);
	return (cnt);
}

int	ft_split_par(char ***temp, char *str, int idx)
{
	char	*buff;
	int		cnt;

	cnt = 0;
	buff = NULL;
	buff = ft_strcjoin(buff, str[idx++]);
	while (str[idx])
	{
		buff = ft_strcjoin(buff, str[idx]);
		if (str[idx] == ')')
			break ;
		idx++;
		cnt++;
	}
	*temp = ft_strsjoin(*temp, buff);
	return (cnt + 1);
}

void	dispaly_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("display: %s\n", str[i]);
		i++;
	}
}