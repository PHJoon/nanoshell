/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:21:39 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

void	relink_env_list(t_env *tmp)
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

int	list_unset(char **temp, t_env **env_list)
{
	t_env	*tmp;
	int		i;

	if (!ft_strscmp(temp[0], "unset"))
		return (-1);
	tmp = *env_list;
	while (tmp)
	{
		i = 1;
		while (temp[i])
		{
			if (!valid_check(temp[i]))
				return (i);
			if (ft_strscmp(tmp->key, temp[i]))
			{
				relink_env_list(tmp);
				free(tmp->key);
				free(tmp->value);
				free(tmp);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	do_unset(char **temp, t_env **env_list, t_env **export_list)
{
	int	res1;
	int	res2;

	res1 = list_unset(temp, env_list);
	res2 = list_unset(temp, export_list);
	if (res1 == -1)
		return (1);
	else if (res1 > 0)
		return (print_error_3("export: \'", temp[res1], \
			"\': not a valid identifier"));
	return (0);
}
