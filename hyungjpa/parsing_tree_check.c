/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:51:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/12 02:51:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_redir(char *str)
{
	if (!ft_strncmp(str, "<", 2) || !ft_strncmp(str, "<<", 3) || \
	!ft_strncmp(str, ">", 2) || !ft_strncmp(str, ">>", 3))
		return (1);
	return (0);
}

int	check_pipe(char *str)
{
	if (ft_strncmp(str, "|", 2))
		return (0);
	return (1);
}

int	check_str(char *str)
{
	if (check_redir(str))
		return (REDIR);
	else if (check_pipe(str))
		return (PIPE);
	return (WORD);
}
