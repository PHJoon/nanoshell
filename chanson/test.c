/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/02/16 14:03:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	char	*str;
	char	**temp;
	t_tree	*tree;

	str = readline("> ");
	temp = ft_split(str);
	if (syntax_check(temp) == FALSE)
	{
		printf("syntax error\n");
		return (1);
	}
	tree = init_tree(temp);
	return (0);
}
