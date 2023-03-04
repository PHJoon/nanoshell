/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:18:40 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 21:20:11 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

void	execute_cmd(char **cmd, int index, t_tree *tree)
{
	char	**pure_cmd;

	pure_cmd = cmd_get(cmd);
	cmd_check(tree, pure_cmd);
	if (pure_cmd[0] == NULL)
		return ;
	tree->infile = get_ird(cmd);
	tree->outfile = get_ord(cmd);
	tree->pid[index] = fork();
	if (tree->pid[index] == 0)
	{
		g_signal_flag = 1;
		do_signal_handle(CHILD);
		if (index == 0)
			fork_first(tree);
		else if (index == tree->pipe_cnt)
			fork_last(tree);
		else
			fork_mid(tree, index);
	}
	else
		do_signal_handle(WAIT_CHILD);
}

void	execute_pipe(char **temp, t_tree *tree)
{
	char	**cmd;
	int		i;
	int		index;

	i = 0;
	index = 0;
	cmd = NULL;
	setting_pipe(tree);
	while (1)
	{
		if (temp[i] == NULL || ft_strscmp(temp[i], "|") == TRUE)
		{
			execute_cmd(cmd, index, tree);
			index++;
			ft_free_str(cmd);
			cmd = NULL;
			if (temp[i] == NULL)
				break ;
		}
		else
			cmd = ft_strsjoin(cmd, ft_strcpy(temp[i]));
		i++;
	}
	close_pipe_all(tree);
	wait_pid(tree);
}
