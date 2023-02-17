/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:39:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/11 23:39:48 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	check_cd(char *str)
{
	if (!ft_strncmp(str, "cd", 3))
		return (1);
	return (0);
}

int	check_path(char *str)
{
	if (str[0] == '.')
		return (0);
	return (1);
}


void	do_cd(int argc, char **argv)
{
	char	path[1024];
	char	*tmp;

	if (!check_cd(argv[1]))
		return ;
	if (argc == 1)
		exit(0);
	if (argc > 2)
	{
		perror(argv[2]);
		exit(errno);
	}
	if (getcwd(path, 1024) == NULL)
	{
		perror("getcwd error!");
		exit(errno);
	}
	if (check_argc(argv[2]))
	{
		if (!chdir(argv[2]))
			exit(0);
		perror(argv[2]);
		exit(errno);
	}
	tmp = ft_strjoin(path, argv[2] + 2);
}
