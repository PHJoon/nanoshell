/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:18:48 by chanson           #+#    #+#             */
/*   Updated: 2023/02/22 20:27:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

char	*ft_itoa(int num)
{
	char	*str;
	char	*num_str;
	int		n;

	num_str = "0123456789";
	if (num <= 0)
		return (0);
	str = NULL;
	while (num)
	{
		n = num / 10;
		if (n == 0)
		{
			str = ft_strcjoin(str, num_str[num]);
			break ;
		}
		str = ft_strcjoin(str, num_str[n]);
		num /= 10;
	}
	return (str);
}
