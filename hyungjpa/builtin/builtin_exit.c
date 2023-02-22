/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:40:02 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/22 14:40:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	check_exit(char *str)
{
	if (!ft_strncmp(str, "exit", 5))
		return (1);
	return (0);
}

void	do_exit(char **str)
{
	if (!check_exit(str[0]))
		return ;
	printf("exit\n");
	if (str[1])
		perror(str[1]);
	exit(0);
}
