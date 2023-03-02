/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:54:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/18 17:54:03 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	do_pwd(t_info *info)
{
	char	*cwd_buf;

	if (!ft_strscmp(info->cmd[0], "pwd"))
		return (1);
	cwd_buf = (char *)malloc(sizeof(char) * 1024);
	if (!cwd_buf)
		return (print_error_1("malloc error"));
	cwd_buf = getcwd(cwd_buf, 1024);
	printf("%s\n", cwd_buf);
	free(cwd_buf);
	return (0);
}
