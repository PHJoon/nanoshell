/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:46:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/11 21:47:19 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

size_t	str_size(char **str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	check_echo(char *str)
{
	if (!ft_strncmp(str, "echo", 5))
		return (1);
	return (0);
}

int	echo_option(char *str)
{
	size_t	i;

	i = 1;
	if (str == NULL)
	{
		printf("\n");
		return (-1);
	}
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

void	do_echo(char **str)
{
	int		flag;
	size_t	i;

	flag = 1;
	i = 2;
	if (!check_echo(str[1]))
		return ;
	while (echo_option(str[i]) == 1)
	{
		i++;
		flag = 0;
	}
	if (echo_option(str[i]) == -1)
		return ;
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
		if (i != str_size(str))
			printf(" ");
	}
	if (flag)
		printf("\n");
}
