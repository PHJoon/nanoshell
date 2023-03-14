/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:30:07 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 15:18:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	ft_strrchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (s[i] == (char)c)
			return (i);
		i--;
	}
	return (0);
}
