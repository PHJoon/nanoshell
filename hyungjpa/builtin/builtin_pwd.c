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

int	check_pwd(char *str)
{
	if (!ft_strncmp(str, "pwd", 4))
		return (1);
	return (0);
}

void	do_pwd(char **str)
{
	size_t	i;
	char	*cwd_buf;

	i = 1;
	if (!check_pwd(str[0]))
		return ;
	if (str_size(str) > 1)
		return ;
	cwd_buf = getcwd(NULL, 0);
	printf("%s\n", cwd_buf);
	free(cwd_buf);
}
