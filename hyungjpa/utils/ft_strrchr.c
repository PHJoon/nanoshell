/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:26:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

int	ft_strrchr(const char *s, int c)
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
