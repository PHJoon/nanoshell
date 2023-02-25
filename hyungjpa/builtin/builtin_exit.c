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

int	do_exit(char **temp)
{
	int	size;

	if (!ft_strscmp(temp[0], "exit"))
		return (1);
	size = str_size(temp);
	printf("exit");
	if (size == 1 || (size == 2 && check_digit(temp[1])))
		printf("\n");
	else if (size > 2)
		return (print_error_1(": too many arguments"));
	else if (size > 1 && !check_digit(temp[1]))
		return (print_error_3(": ", temp[1], \
		": numeric arguments required"));
	return (0);
}
