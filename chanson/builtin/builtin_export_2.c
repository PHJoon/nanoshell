/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:56 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/03 19:19:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

t_env	*sort_export_list(t_env *export_list)
{
	t_env	*tmp;
	t_env	*tmp_next;
	char	*key_tmp;
	char	*value_tmp;

	tmp = export_list;
	while (tmp)
	{
		tmp_next = tmp->next;
		while (tmp_next)
		{
			if (ft_strscmp(tmp->key, tmp_next->key))
			{
				key_tmp = tmp->key;
				value_tmp = tmp->value;
				tmp->key = tmp_next->key;
				tmp->value = tmp_next->value;
				tmp_next->key = key_tmp;
				tmp_next->value = value_tmp;
			}
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
	}
	return (export_list);
}

t_env	*free_last(t_env *export_list)
{
	t_env	*tmp;

	tmp = export_list;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next->key);
	free(tmp->next->value);
	free(tmp->next);
	tmp->next = NULL;
	return (export_list);
}

t_env	*make_export_list(char **envp)
{
	t_env	*export_list;

	export_list = make_env_list(envp);
	export_list = free_last(export_list);
	export_list = sort_export_list(export_list);
	return (export_list);
}

void	print_export(t_env *export_list)
{
	t_env	*tmp;

	tmp = export_list;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

int	valid_check(char *str)
{
	int	idx;

	idx = 0;
	if (!ft_isalpha(str[idx]))
		return (0);
	idx++;
	while (str[idx])
	{
		if (!ft_isalnum(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}
