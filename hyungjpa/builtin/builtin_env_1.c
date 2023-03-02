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

int	do_env(t_info *info)
{
	t_env	*tmp;

	if (!ft_strscmp(info->cmd[0], "env"))
		return (1);
	if (info->cmd[1])
		return (print_error_3("env: ", info->cmd[1], \
		": No such file or directory"));
	tmp = info->env_list;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

char	**make_envp(char **new_envp, int size, t_env *env_list)
{
	int		idx;
	char	*key_value;
	char	*key_value_tmp;
	t_env	*tmp;

	idx = 0;
	tmp = env_list;
	while (idx < size)
	{
		key_value_tmp = ft_strjoin(tmp->key, "=");
		key_value = ft_strjoin(key_value_tmp, tmp->value);
		free(key_value_tmp);
		new_envp[idx] = key_value;
		tmp = tmp->next;
		idx++;
	}
	new_envp[idx] = NULL;
	return (new_envp);
}

char	**env_to_envp(t_env *env_list)
{
	int		size;
	int		idx;
	t_env	*tmp;
	char	**new_envp;

	size = 0;
	idx = 0;
	tmp = env_list;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	tmp = env_list;
	new_envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new_envp)
		return (NULL);
	new_envp = make_envp(new_envp, size, env_list);
	return (new_envp);
}
