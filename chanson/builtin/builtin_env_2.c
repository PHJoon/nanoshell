/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:46:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

t_env	*make_new_env_list(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_env	*add_env_list(t_env *env_list, char *key, char *value)
{
	t_env	*new;
	t_env	*tmp;

	tmp = env_list;
	new = make_new_env_list(key, value);
	if (env_list == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	return (env_list);
}

t_env	*split_env(t_env *env_list, char *str)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (str[i] != '=')
		i++;
	key = ft_strcpy_index(str, 0, i - 1);
	value = ft_strcpy_index(str, i + 1, ft_strlen(str));
	env_list = add_env_list(env_list, key, value);
	return (env_list);
}

t_env	*make_env_list(char **envp)
{
	t_env	*env_list;

	env_list = NULL;
	while (*envp)
	{
		env_list = split_env(env_list, *envp);
		envp++;
	}
	return (env_list);
}
