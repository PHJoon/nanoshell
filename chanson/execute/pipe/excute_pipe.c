/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:18:40 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	execute_cmd(char **cmd, int index, t_tree *tree)
{
	char	**pure_cmd;

	if (tree->cmd.cmd_head)
		free(tree->cmd.cmd_head);
	if (tree->cmd.cmd_arr)
		ft_free_str(tree->cmd.cmd_arr);
	tree->cmd.cmd_head = NULL;
	tree->cmd.cmd_arr = NULL;
	cmd_check(tree, pure_cmd);
	tree->pid[index] = fork();
	if (tree->pid[index] == 0)
	{
		
	}
}

void	execute_pipe(char **temp, t_tree *tree)
{
	char	**cmd;
	int		i;
	int		index;

	i = -1;
	index = 0;
	cmd = NULL;
	while (temp[++i])
	{
		if (ft_strscmp(temp[i], "|") == TRUE)
		{
			execute_cmd(cmd, index, tree);
			ft_free_str(cmd);
			cmd = NULL;
		}
		else
			cmd = ft_strsjoin(cmd, temp[i]);
	}
}
