/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:36:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 19:48:44 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	print_error_1(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (2);
}

int	print_error_2(char *str1, char *str2)
{
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
	return (2);
}

int	print_error_3(char *str1, char *str2, char *str3)
{
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	write(2, str3, ft_strlen(str3));
	write(2, "\n", 1);
	return (2);
}
