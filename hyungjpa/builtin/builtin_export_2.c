/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:56 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/17 16:49:57 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

t_env_list	*sort_export_list(t_env_list *export_list)
{
	t_env_list	*tmp;
	t_env_list	*tmp_next;
	char		*key_tmp;
	char		*value_tmp;

	tmp = export_list;
	while (tmp)
	{
		tmp_next = tmp->next;
		while (tmp_next)
		{
			if (ft_strncmp(tmp->key, tmp_next->key, ft_strlen(tmp->key)) > 0)
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

t_env_list	*free_last(t_env_list *export_list)
{
	t_env_list	*tmp;

	tmp = export_list;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	return (export_list);
}

t_env_list	*make_export_list(char **envp)
{
	t_env_list	*export_list;

	export_list = make_env_list(envp);
	export_list = free_last(export_list);
	export_list = sort_export_list(export_list);
	return (export_list);
}
