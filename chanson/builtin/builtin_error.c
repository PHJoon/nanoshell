/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:36:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

int	print_error_1(char *str)
{
	printf("%s\n", str);
	return (2);
}

int	print_error_2(char *str1, char *str2)
{
	printf("%s", str1);
	printf("%s\n", str2);
	return (2);
}

int	print_error_3(char *str1, char *str2, char *str3)
{
	printf("%s", str1);
	printf("%s", str2);
	printf("%s\n", str3);
	return (2);
}
