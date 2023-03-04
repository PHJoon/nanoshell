/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:18:40 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 20:19:07 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	set_execute_cmd(t_tree *tree)
{
	if (tree->cmd.cmd_head)
		free(tree->cmd.cmd_head);
	if (tree->cmd.cmd_arr)
		ft_free_str(tree->cmd.cmd_arr);
	tree->cmd.cmd_head = NULL;
	tree->cmd.cmd_arr = NULL;
	tree->infile = 0;
	tree->outfile = 0;
	tree->child_status = 0;
}

void	execute_cmd(char **cmd, int index, t_tree *tree)
{
	char	**pure_cmd;

	set_execute_cmd(tree);
	pure_cmd = cmd_get(cmd);
	cmd_check(tree, pure_cmd);
	if (tree->cmd.cmd_head == NULL)
		printf("cmd not valid: %s\n", tree->cmd.cmd_arr[0]);
	tree->infile = get_ird(cmd);
	tree->outfile = get_ord(cmd);
	if (pure_cmd[0] == NULL)
		return ;
	tree->pid[index] = fork();
	if (tree->pid[index] == 0)
	{
		if (index == 0)
			fork_first(tree);
		else if (index == tree->pipe_cnt)
			fork_last(tree);
		else
			fork_mid(tree, index);
	}
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
