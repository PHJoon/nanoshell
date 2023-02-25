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

t_env_list	*list_unset(char **str, t_env_list *env_list)
{
	t_env_list	*tmp;
	size_t		i;

	if (!ft_strscmp(str[0], "unset"))
		return (env_list);
	tmp = env_list;
	while (tmp)
	{
		i = 1;
		while (str[i])
		{
			if (ft_strscmp(tmp->key, str[i]))
			{
				relink_env_list(tmp);
				free(tmp->key);
				free(tmp->value);
				free(tmp);
			}
		}
		tmp = tmp->next;
	}
	return (env_list);
}

void	do_unset(char **temp, t_env_list **env_list, t_env_list **export_list)
{
	*env_list = list_unset(temp, *env_list);
	*export_list = list_unset(temp, *export_list);
}
