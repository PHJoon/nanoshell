/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:27 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 19:48:27 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	ft_strscmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str1[i] != str2[i])
			return (FALSE);
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		i++;
	}
	return (TRUE);
}
