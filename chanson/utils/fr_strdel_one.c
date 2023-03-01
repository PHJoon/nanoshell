/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strdel_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:53:49 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*fr_strdel_one(char *str, int index)
{
	char	*temp;
	int		i;
	int		cnt;

	cnt = ft_strlen(str);
	if (cnt == 0)
		return (0);
	temp = (char *)malloc(sizeof(char) * cnt);
	temp[cnt - 1] = '\0';
	i = 0;
	while (i < cnt - 1)
	{
		if (i == index)
		{
			i++;
			continue ;
		}
		temp[i] = str[i];
		i++;
	}
	free(str);
	return (temp);
}
