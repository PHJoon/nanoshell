/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:12:07 by chanson           #+#    #+#             */
/*   Updated: 2023/02/26 21:31:51 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

static void	clear_terminal(t_tree *tree)
{
	while (tree->cusor.col)
	{
		--(tree->cusor.col);
		tputs(tgoto(tree->cusor.cm, tree->cusor.col, tree->cusor.row), \
			1, putchar_tc);
		tputs(tree->cusor.ce, 1, putchar_tc);
	}
}

void	history_up(t_tree *tree, char *string)
{
	char		*str;
	static int	i;
	int			end;
	static char	*discrim;

	clear_terminal(tree);
	if (ft_strscmp(discrim, string) == FALSE)
	{
		free(discrim);
		discrim = ft_strcpy(string);
		i = 0;
	}
	end = 0;
	while (tree->history[end])
		end++;
	end--;
	str = ft_strcpy(tree->history[end - i]);
	write(0, str, ft_strlen(str));
	free(str);
	if (i <= end)
		i++;
}

void	history_down(t_tree *tree, char *string)
{
	char		*str;
	static int	i;
	int			end;
	static char	*discrim;

	clear_terminal(tree);
	if (ft_strscmp(discrim, string) == FALSE)
	{
		free(discrim);
		discrim = ft_strcpy(string);
		i = 0;
	}
	end = 0;
	while (tree->history[end])
		end++;
	end--;
	str = ft_strcpy(tree->history[i]);
	write(0, str, ft_strlen(str));
	free(str);
	if (i <= end)
		i++;
}
