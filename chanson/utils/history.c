/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:12:07 by chanson           #+#    #+#             */
/*   Updated: 2023/02/26 18:43:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void	history_up(t_tree *tree, char *str)
{
	char		*str;
	static int	i;
	int			end;
	static char	*discrim;

	if (ft_strscmp(discrim, str) == FALSE)
	{
		free(discrim);
		discrim = ft_strcpy(str);
		i = 0;
	}
	end = 0;
	while (tree->history[end])
		end++;
	end--;
	str = ft_strcpy(tree->history[end]);
	write(0, str, ft_strlen(str));
	free(str);
}
