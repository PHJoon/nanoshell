/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:40:02 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 19:57:50 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	check_digit(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
		idx++;
	if (idx == ft_strlen(str))
		return (1);
	return (0);
}

int	do_exit(t_tree *info)
{
	int	size;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "exit"))
		return (1);
	size = str_size(info->cmd.cmd_arr);
	printf("exit");
	if (size == 1 || (size == 2 && check_digit(info->cmd.cmd_arr[1])))
		printf("\n");
	else if (size > 2)
		return (print_error_1(": too many arguments"));
	else if (size > 1 && !check_digit(info->cmd.cmd_arr[1]))
		return (print_error_3(": ", info->cmd.cmd_arr[1], \
		": numeric arguments required"));
	return (0);
}
