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

void	do_pwd(char **str)
{
	size_t	i;
	char	*cwd_buf;

	i = 1;
	if (ft_strscmp(str[0], "pwd"))
		return ;
	if (str_size(str) > 1)
		return ;
	cwd_buf = getcwd(NULL, 0);
	printf("%s\n", cwd_buf);
	free(cwd_buf);
}
