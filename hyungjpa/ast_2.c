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

t_node	*make_new(char *str, int t)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->type = t;
	new->data = str;
	return (new);
}

t_node	*add_back(t_node *head, char *str, int t)
{
	t_node	*new;
	t_node	*tmp;

	new = make_new(str, t);
	tmp = head;
	if (head == NULL)
		head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (head);
}

char	**ft_split_substr(char **temp, size_t start, size_t end)
{
	char	**res;
	size_t	len;
	size_t	i;

	i = 0;
	len = end - start + 2;
	res = (char **)malloc(sizeof(char *) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = temp[start];
		i++;
		start++;
	}
	return (res);
}