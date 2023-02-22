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

int	check_unset(char *str)
{
	if (!ft_strncmp(str, "unset", 6))
		return (1);
	return (0);
}

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

t_env_list	*do_unset(char **str, t_env_list *env_list)
{
	t_env_list	*tmp;
	size_t		i;

	if (!check_unset(str[0]))
		return (env_list);
	tmp = env_list;
	while (tmp)
	{
		i = 1;
		while (str[i])
		{
			if (ft_strncmp(tmp->key, str[i], ft_strlen(str[i]) + 1))
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
