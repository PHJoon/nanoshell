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

int	main(int ac, char **av, char **envp)
{
	char	*str;
	t_node	*root;

	root = NULL;
	while (1)
	{
		str = readline(">$ : ");
		root = list_to_tree(str);
		preorderprint(root);
		printf("\n");
		printf("str: %s\n", str);
		add_history(str);
		free(str);
		root = NULL;
	}
	return (0);
}