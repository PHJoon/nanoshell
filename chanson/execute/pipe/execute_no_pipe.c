/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_no_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:34:55 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 18:18:13 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	_execute_cmd(t_tree *tree)
{
	int	builtin_num;

	do_signal_handle(CHILD);
	if (tree->infile != 0)
	{
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error1\n");
	}
	if (tree->outfile != 0)
	{
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error2\n");
	}
	builtin_num = builtin(tree);
	if (builtin_num != 1)
		exit(builtin_num);
	else
	{
		if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
			ft_error("cmd option error child\n");
	}
}

static void	set_execute_cmd(t_tree *tree)
{
	tree->cmd.cmd_head = NULL;
	tree->cmd.cmd_arr = NULL;
	tree->infile = 0;
	tree->outfile = 0;
	tree->child_status = 0;
}

void	execute_no_pipe(char **temp, t_tree *tree)
{
	int		pid;
	char	**pure_cmd;

	if (tree->cmd.cmd_head)
		free(tree->cmd.cmd_head);
	if (tree->cmd.cmd_arr)
		ft_free_str(tree->cmd.cmd_arr);
	set_execute_cmd(tree);
	pure_cmd = cmd_get(temp);
	cmd_check(tree, pure_cmd);
	if (tree->cmd.cmd_head == NULL)
		printf("cmd not valid: %s\n", tree->cmd.cmd_arr[0]);
	tree->infile = 0;
	tree->outfile = 0;
	tree->infile = get_ird(temp);
	tree->outfile = get_ord(temp);
	if (pure_cmd[0] == NULL)
		return ;
	pid = fork();
	if (pid == 0)
		_execute_cmd(tree);
	else
		waitpid(pid, &tree->child_status, 0);
}
