/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:47:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/14 14:47:06 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_lst	*new_list(char *str)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->data = str;
	new->next = NULL;
	return (new);
}

void	add_next(t_lst_info *info, char *str)
{
	t_lst	*new;

	new = new_list(str);
	if (info->head == NULL)
		info->head = new;
	else
		info->tail->next = new;
	info->tail = new;
}

t_lst_info	*init_lst_info(void)
{
	t_lst_info	*info;

	info = (t_lst_info *)malloc(sizeof(t_lst_info));
	if (!info)
		return (NULL);
	info->head = NULL;
	info->tail = NULL;
	return (info);
}
