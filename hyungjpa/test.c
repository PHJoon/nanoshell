/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/14 16:22:51 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_node	*root;

void	free_split(char **tmp, int i)
{
	while (i > 0)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i--;
	}
	free(tmp);
	tmp = NULL;
}

int	main(int ac, char **av)
{
	char		*str;
	t_lst_info	*info;
	t_lst		*tmp;
	t_node		*root;
	t_node		*root_tmp;

	root = NULL;
	while (1)
	{
		str = readline(">$ : ");
		info = line_parsing(str);
		tmp = info->head;
		while (tmp)
		{
			printf("%s\n", tmp->data);
			tmp = tmp->next;
		}
		root = insert(root, info->head->data);
		root_tmp = root;
		info->head = info->head->next;
		while (info->head)
		{
			root = insert(root, info->head->data);
			if (check_av(info->head->data) == 3)
				root = root->right;
			info->head = info->head->next;
		}
		preorderprint(root_tmp);
		printf("\n");
		printf("str: %s\n", str);
		add_history(str);
		free(str);
		root = NULL;
	}
	return (0);
}
