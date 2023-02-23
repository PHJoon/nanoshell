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

void	do_exit(char **str)
{
	if (!ft_strscmp(str[0], "exit"))
		return ;
	printf("exit\n");
	if (str[1])
		perror(str[1]);
	exit(0);
}
