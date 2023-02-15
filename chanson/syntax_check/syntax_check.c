/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:23:35 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 14:30:53 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

static void	make_type_list(int *type_list, int end)
{
	enum e_token	type;
	int				i;

	i = 0;
	while (i < end)
	{
		
	}
}

int	syntax_check(char **temp)
{
	int		idx;

	idx = 0;
	while (temp[idx])
		idx++;
	type_list = (int *)malloc(sizeof(int) * (idx));
	make_type_list(type_list, idx);
}
