/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:39:23 by chanson           #+#    #+#             */
/*   Updated: 2023/02/13 16:23:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcjoin(char *s, char c)
{
	char	*temp;
	int		i;

	if (s == NULL)
	{
		temp = (char *)malloc(sizeof(char) * 2);
		temp[0] = c;
		temp[1] = '\0';
	}
	else
	{
		temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
		i = -1;
		while (s[++i])
			temp[i] = s[i];
		temp[i++] = c;
		temp[i] = '\0';
	}
	free(s);
	return (temp);
}
