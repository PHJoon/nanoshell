/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:21:39 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/17 16:21:41 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	relink_env_list(t_env_list *tmp)
{
	if (tmp->prev)
	{
		if (tmp->next)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		else
			tmp->prev->next = NULL;
	}
	else
	{
		if (tmp->next)
			tmp->next->prev = NULL;
	}
}

t_env_list	*do_unset(t_env_list *env_list, char *key)
{
	t_env_list	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strscmp(tmp->key, key))
		{
			relink_env_list(tmp);
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return (env_list);
		}
		tmp = tmp->next;
	}
	return (env_list);
}
