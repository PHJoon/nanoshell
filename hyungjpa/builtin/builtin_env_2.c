/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:46:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/17 15:46:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

t_env_list	*make_new_env_list(char *key, char *value)
{
	t_env_list	*new;

	new = (t_env_list *)malloc(sizeof(t_env_list));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_env_list	*add_env_list(t_env_list *env_list, char *key, char *value)
{
	t_env_list	*new;
	t_env_list	*tmp;

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

t_env_list	*split_env(t_env_list *env_list, char *str)
{
	size_t	i;
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

t_env_list	*make_env_list(char **envp)
{
	t_env_list	*env_list;

	env_list = NULL;
	while (*envp)
	{
		env_list = split_env(env_list, *envp);
		envp++;
	}
	return (env_list);
}
