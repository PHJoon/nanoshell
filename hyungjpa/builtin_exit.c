/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:37:26 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/12 01:37:27 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_exit(char *str)
{
	if (!ft_strncmp(str, "exit", 5))
		return (1);
	return (0);
}

int	check_argv(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	do_exit(int argc, char **argv)
{
	if (!check_exit(argv[1]))
		return ;
	if (argc > 2)
	{
		perror("exit error!");
		return ;
	}
	if (argc == 1)
		return ;
	printf("exit\n");
	if (!check_argv(argv[2]))
	{
		perror(argv[2]);
		return ;
	}
	



}
