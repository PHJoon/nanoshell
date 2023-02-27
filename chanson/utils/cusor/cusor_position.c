/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cusor_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:14:37 by chanson           #+#    #+#             */
/*   Updated: 2023/02/27 17:21:05 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.h"

static int	nbr_length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	get_cusor_start(t_cusor *cusor)
{
	int		a;
	int		i;
	char	buf[255];
	int		ret;

	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	a = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				cusor->row = ft_atoi(&buf[i]) - 1;
			else
				cusor->col = ft_atoi(&buf[i]) - 1;
			a++;
			i += nbr_length(cusor->col + 1) - 1;
		}
		i++;
	}
	cusor->start = cusor->col;
	cusor->end = cusor->col;
}
