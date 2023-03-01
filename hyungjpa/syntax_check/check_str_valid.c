/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:05:13 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/test.h"

int	check_str_valid(char *str)
{
	int	single_quote_flag;
	int	double_quote_flag;
	int	parentheses_flag;
	int	idx;

	single_quote_flag = 0;
	double_quote_flag = 0;
	parentheses_flag = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '(')
			parentheses_flag++;
		else if (str[idx] == ')')
			parentheses_flag--;
		else if (str[idx] == '\'')
			single_quote_flag++;
		else if (str[idx] == '\"')
			double_quote_flag++;
		idx++;
	}
	if (parentheses_flag != 0 || single_quote_flag % 2 != 0 \
		|| double_quote_flag % 2 != 0)
		return (FALSE);
	return (TRUE);
}
