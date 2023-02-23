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

void	do_env(char **str, t_env_list *env_list)
{
	t_env_list	*tmp;

	if (!ft_strscmp(str[0], "env"))
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
