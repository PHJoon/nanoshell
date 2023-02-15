/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:41:16 by chanson           #+#    #+#             */
/*   Updated: 2023/02/15 16:59:06 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

static int	_check_pattern(int rt, int rtb)
{
	if (rt == TK_STR && rtb == TK_LPT)
		return (FALSE);
	if (rt == TK_IRD && rtb == TK_STR)
		return (TRUE);
	if (rt == TK_ORD && rtb == TK_STR)
		return (TRUE);
	if (rt == TK_HRD && rtb == TK_STR)
		return (TRUE);
	if (rt == TK_ARD && rtb == TK_STR)
		return (TRUE);
	if (rt == TK_PIPE && (rtb == TK_PIPE || \
	rtb == TK_AND || rtb == TK_OR || rtb == TK_RPT))
		return (FALSE);
	if (rt == TK_AND && (rtb == TK_PIPE || rtb == TK_AND \
		|| rtb == TK_OR || rtb == TK_RPT))
		return (FALSE);
	if (rt == TK_OR && (rtb == TK_PIPE || rtb == TK_AND \
		|| rtb == TK_OR || rtb == TK_RPT))
		return (FALSE);
	if (rt == TK_LPT && (rtb == TK_PIPE || rtb == TK_AND \
		|| rtb == TK_OR || rtb == TK_RPT))
		return (FALSE);
	if (rt == TK_RPT && (rtb == TK_STR || rtb == TK_LPT))
		return (FALSE);
	return (TRUE);
}

int	check_pattern(char **temp, int *type_list, int idx)
{
	int	real_type;
	int	real_type_back;
	int	i;

	i = 0;
	real_type = type_list[idx];
	real_type_back = type_list[idx + 1];
	if (type_list[idx] == TK_STR)
	{
		while (temp[idx][i])
			i++;
		if (temp[idx][i - 1] == '(')
			return (FALSE);
		if (temp[idx][i - 1] == ')')
			real_type = TK_RPT;
	}
	if (type_list[idx + 1] == TK_STR)
	{
		if (temp[idx + 1][0] == '(')
			real_type = TK_LPT;
		if (temp[idx + 1][0] == ')')
			return (FALSE);
	}
	return (_check_pattern(real_type, real_type_back));
}
