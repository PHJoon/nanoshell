/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:53:32 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/09 11:53:33 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static int	echo_option(char *str)
{
	int	i;

	i = 1;
	if (str == NULL)
	{
		printf("\n");
		return (-1);
	}
	if (ft_strscmp(str, " "))
		return (1);
	if (str[0] == '-')
	{
		while (str[i] == 'n')
			i++;
		if (i != ft_strlen(str) || i == 1)
			return (0);
		return (1);
	}
	return (0);
}

int	check_echo_option(char **temp, int *i, int *flag)
{
	if (echo_option(temp[*i]) == -1)
	{
		ft_free_str(temp);
		return (0);
	}
	while (echo_option(temp[*i]) == 1)
	{
		if (ft_strscmp(temp[*i], " "))
		{
			(*i)++;
			continue ;
		}
		(*i)++;
		*flag = 0;
	}
	return (1);
}
