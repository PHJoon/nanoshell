/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:48:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/12 04:48:54 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_ascii(char c)
{
	// " 34, ' 39, < 60, > 62, | 124 
	if (c == 34)
		return (1);
	if (c == 39)
		return (2);
	if (c == 32)
		return (3);
	if (c == 60)
		return (4);
	if (c == 62)
		return (5);
	if (c == 124)
		return (6);
	return (0);
}

void	quote_and_str(char *str, int sign, size_t *cnt, size_t j)
{
	if (sign < 3 && sign != 0)
	{
		while ((check_ascii(str[j]) != sign) && str[j])
		{
			*cnt += 1;
			j++;
		}
		*cnt += 1;
	}
	else
	{
		while ((check_ascii(str[j]) == sign) && str[j])
		{
			*cnt += 1;
			j++;
		}
	}
}

void	not_space(t_lst_info *info, char *str, int sign, size_t *i)
{
	size_t	cnt;
	size_t	j;

	cnt = 1;
	j = *i + 1;
	if (sign > 3)
	{
		if (str[j] && (check_ascii(str[j]) == sign))
			cnt++;
	}
	else
		quote_and_str(str, sign, &cnt, j);
	add_next(info, ft_substr(str, *i, cnt));
	*i += cnt;
}

t_lst_info	*line_parsing(char *str)
{
	t_lst_info	*info;
	size_t		i;
	int			sign;
	int			cnt;

	info = init_lst_info();
	i = 0;
	while (str[i])
	{
		sign = check_ascii(str[i]);
		if (sign == 3)
		{
			while ((check_ascii(str[i]) == sign) && str[i])
				i++;
		}
		else
			not_space(info, str, sign, &i);
	}
	return (info);
}
