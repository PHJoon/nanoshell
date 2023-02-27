/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cusor_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:58:54 by chanson           #+#    #+#             */
/*   Updated: 2023/02/27 19:43:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.h"

int	putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	move_cursor_left(t_cusor *cusor)
{
	if (cusor->col == cusor->start)
		return ;
	--(cusor->col);
	tputs(tgoto(cusor->cm, cusor->col, cusor->row), 1, putchar_tc);
}

void	move_cursor_right(t_cusor *cusor)
{
	if (cusor->col >= cusor->end)
		return ;
	++(cusor->col);
	tputs(tgoto(cusor->cm, cusor->col, cusor->row), 1, putchar_tc);
}

void	delete_end(t_cusor *cusor)
{
	if (cusor->col != cusor->start)
	{
		--(cusor->col);
		--(cusor->end);
	}
	tputs(tgoto(cusor->cm, cusor->col, cusor->row), 1, putchar_tc);
	tputs(cusor->ce, 1, putchar_tc);
}
