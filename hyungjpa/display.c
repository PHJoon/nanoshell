/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:38:15 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/03 19:51:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

void	display_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
}

void	display_list_envp(t_env *node)
{
	t_env	*temp;

	temp = node;
	while (temp)
	{
		printf("key: %s val: %s\n", node->key, node->value);
		temp = temp->next;
	}
}
