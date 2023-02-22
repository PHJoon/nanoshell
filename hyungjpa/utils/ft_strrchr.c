/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:26:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/22 19:26:42 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

size_t	ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (i);
		i--;
	}
	return (0);
}
