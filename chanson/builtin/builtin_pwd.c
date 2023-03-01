/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:54:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

int	do_pwd(char **temp)
{
	char	*cwd_buf;

	if (!ft_strscmp(temp[0], "pwd"))
		return (1);
	cwd_buf = (char *)malloc(sizeof(char) * 1024);
	if (!cwd_buf)
		return (print_error_1("malloc error"));
	cwd_buf = getcwd(cwd_buf, 1024);
	printf("%s\n", cwd_buf);
	free(cwd_buf);
	return (0);
}
