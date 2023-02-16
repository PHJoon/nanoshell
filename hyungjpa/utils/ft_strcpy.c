/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:26:21 by chanson           #+#    #+#             */
/*   Updated: 2023/02/13 17:28:52 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

char	*ft_strcpy(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	temp[i] = '\0';
	i = 0;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}
