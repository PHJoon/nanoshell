/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:09 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/22 14:52:11 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	check_env(char *str)
{
	if (!ft_strncmp(str, "env", 4))
		return (1);
	return (0);
}

void	do_env(char **str, t_env_list *env_list)
{
	t_env_list	*tmp;

	if (!check_env(str[0]))
		return ;
	if (str[1])
	{
		perror(str[1]);
		return ;
	}
	tmp = env_list;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
