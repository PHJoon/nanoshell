/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:53:51 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 20:57:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

t_tree	*make_tree(char **temp)
{
	int		*type_list;
	int		i;

	i = 0;
	while (temp[i])
		i++;
	type_list = (int *)malloc(sizeof(int) * i);
	make_type_list()
}
