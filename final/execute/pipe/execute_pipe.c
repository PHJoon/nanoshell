/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:18:40 by chanson           #+#    #+#             */
/*   Updated: 2023/03/09 17:15:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

void	set_execute_cmd(t_tree *tree)
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

static void	child_execute(t_tree *tree, int index)
{
	g_signal_flag = 1;
	set_child_mode(tree);
	do_signal_handle(CHILD);
	if (index == 0)
		fork_first(tree);
	else if (index == tree->pipe_cnt)
		fork_last(tree);
	else
		fork_mid(tree, index);
}

void	execute_cmd(char **cmd, int index, t_tree *tree)
{
	char	**pure_cmd;

	set_execute_cmd(tree);
	display_str(cmd);
	pure_cmd = cmd_get(cmd);
	pure_cmd = ft_erase_null(pure_cmd);
	change_env_val(pure_cmd, tree);
	cmd_check(tree, pure_cmd);
	tree->infile = get_ird(cmd);
	if (tree->infile == -1)
		return ;
	tree->outfile = get_ord(cmd);
	if (pure_cmd[0] == NULL)
		return ;
	printf("index: %d\n", index);
	printf("hihi %d %d\n", tree->pipe_cnt, tree->pid[index]);
	tree->pid[index] = fork();
	if (tree->pid[index] == 0)
	{
		printf("hello child\n");
		child_execute(tree, index);
	}
	else
	{
		printf("%d\n", tree->pid[index]);
		do_signal_handle(WAIT_CHILD);
		parent_unset_export(tree);
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
	// ft_free_str(tree->echo_arr);
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
		printf("%s\n", temp[i]);
		i++;
	}
	close_pipe_all(tree);
	wait_pid(tree);
}
