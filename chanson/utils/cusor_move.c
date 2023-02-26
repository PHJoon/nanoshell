/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cusor_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:58:54 by chanson           #+#    #+#             */
/*   Updated: 2023/02/26 20:02:32 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	move_cursor_left(int *col, int *row, char *cm)
{
	if (*col == 0)
		return ;
	--(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);
}

void	move_cursor_right(int *col, int *row, char *cm, int *end)
{
	if (*col > *end)
		return ;
	++(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);
}
