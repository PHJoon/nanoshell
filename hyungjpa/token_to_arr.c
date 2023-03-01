/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:32:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/01 12:32:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

char	**token_to_arr(t_token *cmd)
{
	t_token	*tmp;
	int		size;
	char	**new_cmd;

	tmp = cmd;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->right;
	}
	new_cmd = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new_cmd)
		return (NULL);
	tmp = cmd;
	size = 0;
	while (tmp)
	{
		new_cmd[size] = tmp->val;
		tmp = tmp->right;
		size++;
	}
	new_cmd[size] = NULL;
	return (new_cmd);
}
