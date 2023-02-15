/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:12:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/15 18:12:30 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	make_type_list(int *type_list, char **temp)
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

t_token	*make_new(char *str, int t)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->next = NULL;
	new->type = t;
	new->val = str;
	return (new);
}

void	inorderprint(t_token *root)
{
	if (root == NULL)
		return ;
	inorderprint(root->left);
	printf("%s:%d\n", root->val, root->type);
	if (root->next)
		printf("%s:%d\n", root->next->val, root->next->type);
	inorderprint(root->right);
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

int	*split_typelist(int *type_list, size_t start, size_t end)
{
	int	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = end - start + 1;
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = type_list[start];
		i++;
		start++;
	}
	return (res);
}

int	check_type(int *right_type, int type, int size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (right_type[i] == type)
			return (0);
		i++;
	}
	return (1);
}


t_token	*make_tree(t_token *root, char **temp, int *type_list, int type)
{
	char	**left_temp;
	char	**right_temp;
	int		*left_type;
	int		*right_type;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (temp[cnt])
		cnt++;
	while (temp && i < cnt)
	{
		if (type_list[i] == TK_AND || TK_OR)
			break ;
		i++;
	}
	root = make_new(temp[i], type_list[i]);
	if (i == 0)
		return (NULL);
	left_temp = ft_split_substr(temp, 0, i - 1);
	right_temp = ft_split_substr(temp, i + 1, cnt);
	left_type = split_typelist(type_list, 0, i - 1);
	right_type = split_typelist(type_list, i + 1, cnt);
	root->left = make_tree(root, left_temp, left_type, type - 1);
	if (check_type(right_type, type, cnt - i))
		type--;
	root->right = make_tree(root, right_temp, right_type, type);
	return (root);
}

t_token	*split_to_tree(char **temp)
{
	int		*type_list;
	int		cnt;
	int		i;
	t_tree	*tree;
	t_token	*root;

	cnt = 0;
	i = 0;
	root = NULL;
	while (temp[cnt])
		cnt++;
	type_list = (int *)malloc(sizeof(int) * (cnt));
	if (!type_list)
		return (FALSE);
	make_type_list(type_list, temp);
	tree = (t_tree *)malloc(sizeof(t_tree));
	root = make_tree(root, temp, type_list, 7);
	return (root);
}