/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:43:25 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/11 23:43:26 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	check_pwd(char **argv)
{
	if (!ft_strncmp(argv[1], "pwd", 4))
		return (1);
	return (0);
}

void	do_pwd(int argc, char **argv)
{
	char	path[1024];

	if (!check_pwd(argv))
		return ;
	if (argc > 2)
	{
		perror(argv[2]);
		return ;
	}
	if (getcwd(path, 1024) == NULL)
	{
		perror("getcwd error!");
		return ;
	}
	printf("%s\n", path);
	return ;
}
