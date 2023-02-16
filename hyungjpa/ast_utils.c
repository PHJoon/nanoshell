/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:23:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/16 13:23:50 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	make_type_list(int *type_list, char **temp)
{
	enum e_token	type;
	int				i;

	i = -1;
	while (temp[++i])
	{
		if (ft_strscmp(temp[i], "<") == TRUE)
			type_list[i] = TK_IRD;
		else if (ft_strscmp(temp[i], ">") == TRUE)
			type_list[i] = TK_ORD;
		else if (ft_strscmp(temp[i], "<<") == TRUE)
			type_list[i] = TK_HRD;
		else if (ft_strscmp(temp[i], ">>") == TRUE)
			type_list[i] = TK_ARD;
		else if (ft_strscmp(temp[i], "|") == TRUE)
			type_list[i] = TK_PIPE;
		else if (ft_strscmp(temp[i], "&&") == TRUE)
			type_list[i] = TK_AND;
		else if (ft_strscmp(temp[i], "||") == TRUE)
			type_list[i] = TK_OR;
		else
			type_list[i] = TK_STR;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
